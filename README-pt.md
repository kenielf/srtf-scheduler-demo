# Escalonamento SRTF
## Sobre
Uma demonstração do algoritmo de escalonamento de 
[Tempo Remanescente Mais Curto Primeiro] -- do inglês *(Shortest Remaining Time First)*.

[Tempo Remanescente Mais Curto Primeiro]:
https://pt.wikipedia.org/wiki/Shortest_remaining_time (Tempo Remanescente Mais Curto Primeiro)

Apesar deste projeto ter sido montado para uma apresentação da matéria de 
sistemas operacionais de uma faculdade, contribuições como *issues*, 
*pull requests*, e discussões são bem-vindas.

## Compilação
> [!WARNING]
> Para usuários de windows: o programa funciona normalmente no `cmd.exe` se
> estiverem habilitadas as [Sequências de terminais virtuais do console].
>
> Se isso não for uma opção para você, tente com um terminal com suporte pra
> formatos de texto ricos, como o [GitBash]

[Sequências de terminais virtuais do console]:
https://learn.microsoft.com/pt-br/windows/console/console-virtual-terminal-sequences (Sequências de terminais virtuais do console)

[GitBash]:
https://gitforwindows.org/index.html (GitBash)


Clone o repositório e use o `gcc` para buildar o projeto:
```bash
git clone 'https://github.com/kenielf/srtf-scheduler-demo.git'
cd srtf-scheduler-demo
gcc -Wall -Wextra -Wpedantic -Wshadow -o main src/*{c,h}
```

## Execução
Use `./main` em plataformas unix-like ou simplesmente `main` no Windows.

