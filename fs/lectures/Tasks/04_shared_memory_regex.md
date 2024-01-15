# 4. Shared memory + Regex

Write two programs:

1. `unsearcher.c`:
   * `./unsearcher /shmem_id "regex"`.
   * Opens [shared memory object](https://man7.org/linux/man-pages/man7/shm_overview.7.html)
     with `/shmem_id` descriptor.
   * Prints all the lines that ''not'' contain `regex`.
1. `filler.c`
   * `./filler /shmem_id textfile`.
   * Fills shared memory object with contents of the `textfile`.
   * If `textfile` is too large, simply ignore the rest of it.
