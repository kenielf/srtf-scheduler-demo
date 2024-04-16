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


Clone the repository and use `gcc` to build the project:
```bash
git clone 'https://github.com/kenielf/srtf-scheduler-demo.git'
cd srtf-scheduler-demo
gcc -Wall -Wextra -Wpedantic -Wshadow -o main src/*{c,h}
```

## Executing
Use `./main` on unix-like platforms or just simply `main` on Windows.

