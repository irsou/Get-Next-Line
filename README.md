# Get-Next-Line

## 🚀 Purpose

To develop a C function that can read lines of any length from a file or standard input.

The function must read a file line by line with buffering (without storing the whole file in memory).
This implies a proper buffer management and file descriptor handling, with an acurate usage of read(), malloc(), and free().

## 📦🔒 About static buffers

A static buffer is a fixed-sized space in memory where data is stored for a limited time. In contrast to the dynamic buffers, which can grow or shrink during runtime, static buffers have a predetermined size that does not change. They are often used to optimize performance and enhance memory management for low-level programming languages. 

## 🖥️📄 About file descriptors:

1. What is a file descriptor?
A file descriptor, FD, is an integer that represents an open file in a process. Each process has its own table of file descriptors under UNIX-like operating systems like Linux and macOS. Essentially, when openning a file, the systems returns a fd that can be used to read/write that file.

Traditionally, the first three FDs are reserved:

0 → stdin (standard input, default is keyboard)
1 → stdout (standard output, default is screen)
2 → stderr (standard error output, also defaults to screen)
These are not actual files but are a set of pointers for input streams and output streams.

2. Structures in an operating system
The kernel employs various structures for access control if a process opens a file.

(A) File Descriptor Table - In the Process
Each process maintains a table where the file descriptors are indexes in an array. Each index in this array points to some structure in the kernel, which is representative of the open file.

(B) Global File Entry Table (in the kernel)
This table at the system level maintains the list of open files, including:

The current position in the file for reading/writing
Access flags: O_RDONLY, O_WRONLY, O_RDWR
A pointer to the inode - the on disk structure representing the file
(C) Inode Table
Each file entry points to an inode and it is actually the inode that contains the information about the file:

Owner
Permissions
Disk location

#### 🌐 More info
[https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/]

## 🧪✅ Testing

cc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c get_next_line_utils.c main_test.c

#### 📝 Other test
[https://github.com/Tripouille/gnlTester]

## 🐞🔍 gdb
gdb ./a.out

(gdb) break ft_strjoin
(gdb) run

(gdb) backtrace



##  🤝Contributions
Contributions are welcome! Open an issue or submit a pull request to suggest improvements or fixes.
