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


### Manual
Clone o repositório e use o `gcc` para buildar o projeto:
```bash
git clone 'https://github.com/kenielf/srtf-scheduler-demo.git'
cd srtf-scheduler-demo
gcc -Wall -Wextra -Wpedantic -Wshadow -o main src/*.c src/*.h
```

---
Para executar, use `./main` em plataformas unix-like ou simplesmente `main` no 
Windows.

### Makefile
> [!NOTE]
> Para o intuito de buildar no linux somente no linux, podendo ter compilação 
> cruzada para o windows com a receita correta, requerindo 
> `x86_64-w64-mingw32-gcc`, que irá buildar o binário `.exe` em conjunto com
> o `elf`.

Clone o repositório da mesma maneira, porém utilize o `make` para preparar o 
binário:
```bash
git clone 'https://github.com/kenielf/srtf-scheduler-demo.git'
cd srtf-scheduler-demo
make build
```

---
Para executar, use `./target/demo`.

## Argumentos
É possível alterar a quantidade de jobs para serem escalonados passando o 
o argumento abaixo para a aplicação:
```bash
./target/demo 8  # Will run 8 jobs instead of the default.
```

