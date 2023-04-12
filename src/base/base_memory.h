#pragma once

#define M_ARENA_DEFAULT_RESERVE_SIZE Gigabytes(1)
#define M_DEFAULT_ALIGNMENT sizeof(void*)
#define M_COMMIT_BLOCK_SIZE Megabytes(64)

typedef struct M_Arena{
                U64 cap;
                U64 pos;
                U64 commit_pos;
} M_Arena;

function M_Arena     *m_arena_reserve_sized(U64 reserve_size);
function M_Arena     *m_arena_reserve(void);
function void        *m_arena_alloc(M_Arena *arena, U64 size);
function void         m_arena_release(M_Arena *arena);