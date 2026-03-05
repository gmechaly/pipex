# Pipex - @42Born2Code

## 💡 About

The **Pipex** project is a deep dive into the inner workings of the UNIX operating system. The goal is to reproduce the behavior of the shell pipeline command: `< file1 cmd1 | cmd2 > file2`.

This project focuses on **process creation**, **pipes**, and **file descriptor redirection**.

---

## 🛠️ The Logic

The program mimics the following shell command:

```bash
$ < infile cmd1 | cmd2 > outfile

```

In C, this involves:

1. **Creating a Pipe**: Using `pipe()` to create a unidirectional data channel.
2. **Forking**: Using `fork()` to create two child processes (one for each command).
3. **Redirection**: Using `dup2()` to swap standard input/output with our file descriptors.
4. **Execution**: Using `execve()` to search for and run the binaries in the system's `PATH`.

---

## 🚀 Usage

### Compilation

To compile the project, run:

```bash
make

```

### Execution

The program takes 4 arguments:

```bash
./pipex infile "cmd1" "cmd2" outfile

```

**Example:**

```bash
./pipex input.txt "ls -l" "wc -l" output.txt

```

This is equivalent to: `< input.txt ls -l | wc -l > output.txt`

---

## 🔍 Technical Implementation

* **Path Resolution**: The program manually parses the `envp` (environment variables) to find the `PATH` and locate the command binaries.
* **Error Handling**: Robust management of "Command not found", "Permission denied", and file access issues, mimicking the shell's exit codes.
* **Memory Management**: All dynamically allocated memory is freed, and all file descriptors are closed to prevent leaks.
