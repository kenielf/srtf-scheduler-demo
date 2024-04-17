# SRTF Scheduling
> [!NOTE]
> Para leitores falantes de português, [clique aqui](/README-pt.md)!

## About
A demonstration of the **[Shortest Remaining Time First]** scheduling
algorithm.

[Shortest Remaining Time First]:
https://en.wikipedia.org/wiki/Shortest_remaining_time (Shortest Remaining Time First)

Although this project was built for a university operating system's class 
presentation assignment, contributions such as issues, pull requests and 
discussions are welcomed.

## Compiling
> [!WARNING]
> For windows users: program works fine on `cmd.exe` if 
> [Console Virtual Terminal Sequences] are enabled accordingly.
>
> If this is not an option for you, try a terminal with rich text support 
> such as [GitBash].

[Console Virtual Terminal Sequences]:
https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences (Console Virtual Terminal Sequences)

[GitBash]:
https://gitforwindows.org/index.html (GitBash)


### Manual
Clone the repository and use `gcc` to build the project:
```bash
git clone 'https://github.com/kenielf/srtf-scheduler-demo.git'
cd srtf-scheduler-demo
gcc -Wall -Wextra -Wpedantic -Wshadow -o main src/*.c src/*.h
```

---
To run it, use `./main` on unix-like platforms or just simply `main` on Windows.

### Makefile
> [!NOTE]
> Intended for building on linux only, and it can cross compile the target to 
> windows with the appropriate recipe, requiring `x86_64-w64-mingw32-gcc`, 
> which will build the `.exe` binary alongside the `elf` one.

Clone the repository in the same manner, but use `make` to prepare the binary 
instead:
```bash
git clone 'https://github.com/kenielf/srtf-scheduler-demo.git'
cd srtf-scheduler-demo
make build
```

---
To run it, use `./target/demo`.

## Arguments
It is possible to override the amount of jobs to schedule by passing it to the
application as shown below:
```bash
./target/demo 8  # Will run 8 jobs instead of the default.
```

