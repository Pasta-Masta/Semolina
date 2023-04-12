#pragma once

int app();

//Memory

function void* os_memory_reserve(U64 size);
function B32   os_memory_commit(void *ptr, U64 size);
function void  os_memory_decommit(void *ptr, U64 size);
function void  os_memory_release(void *ptr, U64 size);