
//gingerbill:  https://www.gingerbill.org/article/2019/02/08/memory-allocation-strategies-002/

#define M_INITIAL_COMMIT Kilobytes(4)
StaticAssert(sizeof(M_Arena) <= M_INITIAL_COMMIT);

#define M_INTERNAL_MIN_SIZE AlignUpPow2(sizeof(M_Arena), 64)

function M_Arena *m_arena_reserve_sized(U64 reserve_size){
	M_Arena *result = 0;
	if(reserve_size >= M_INITIAL_COMMIT){
		void *memory = os_memory_reserve(reserve_size);
		if(os_memory_commit(memory, M_INITIAL_COMMIT)){
			result = (M_Arena*)memory;
			result->cap = reserve_size;
			result->pos = M_INTERNAL_MIN_SIZE;
			result->commit_pos = M_INITIAL_COMMIT;			
		}
	}
	Assert(result != 0);
	return(result);
}

function M_Arena *m_arena_reserve(void){
	return(m_arena_reserve_sized(M_ARENA_DEFAULT_RESERVE_SIZE));
}

function void *m_arena_alloc(M_Arena *arena, U64 size){
	void *result = 0;
	// check allocation fits in arena cap
	if(arena->pos + size <= arena->cap){

		// save the pointer to return
		void  *result_on_success = ((U8 *)arena) + arena->pos;
		
		// check if new memory needs to be committed, if so align to block size and clamp to arena cap
		U64 p = arena->pos + size;
		U64 commit_p = arena->commit_pos;
		if(p > commit_p){
			U64 p_aligned = AlignUpPow2(p, M_COMMIT_BLOCK_SIZE);
			U64 next_commit_p = ClampTop(p_aligned, arena->cap);
			U64 commit_size = next_commit_p - commit_p;
			if(os_memory_commit((U8*)arena + commit_p, commit_size)){
				commit_p = next_commit_p;
				arena->commit_pos = commit_p;
			}
		}
		
		// check allocation fits in commit range and save the allocation
		if(p <= commit_p){
			result = result_on_success;
			arena->pos = p;
		}
	}
	Assert(result != 0);
	return(result);
}

function void m_arena_release(M_Arena *arena){
	os_memory_release(arena, arena->cap);
}