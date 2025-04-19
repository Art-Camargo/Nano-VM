🧠 Nano VM - MIPS-based Virtual Machine

Uma pequena máquina virtual com arquitetura baseada em MIPS, desenvolvida para interpretar e executar programas simples com uma interface de terminal interativa (TUI).

📁 Estrutura do Projeto

vm/
├── main.c # Orquestrador principal
├── loader.cpp # Carrega programas e popula a memória
├── launch.c # Executa as instruções da VM (core da CPU)
├── drop_down_menu.c # Interface TUI para escolha de arquivos
├── dir_options.c # Lê opções de diretório para o menu
├── instructions.h # Define os opcodes e estrutura das instruções
├── launch.h # Interface da função launch_program
└── programs/ # Programas escritos para rodar na VM

🚀 Como funciona

main.cExibe no terminal uma interface interativa (via setas) para o usuário escolher qual programa deseja executar.

loader.cppCarrega o programa escolhido e armazena as instruções e dados nas memórias internas da VM.

launch.cRoda a VM de fato, interpretando instruções em uma arquitetura baseada em MIPS com suporte a registradores, saltos condicionais, leitura e escrita em memória, e entrada/saída básica.

🧱 Arquitetura MIPS Simplificada

Registradores: a0, a1, a2, a3

Instruções suportadas:

Aritméticas: ADD, SUB, MUL, DIV

Memória: MV (load), ST (store)

Saltos: JMP, JEQ, JGT, JLT

I/O: R (read), W (write)

Controle: STP (stop)

💻 Como compilar

g++ main.c launch.c loader.cpp drop_down_menu.c dir_options.c -o vm_launcher

▶️ Como usar

Compile o projeto.

Execute o binário ./vm_launcher.

Navegue com as setas do teclado e escolha um programa.

Observe a execução no terminal — interativa e visual!

🛠️ Futuras melhorias

Suporte a mais registradores

Tipos de dados além de inteiros

Interface gráfica

Debugger simples (step, breakpoints)

👨‍💻 Autor

Feito por Artur de Camargo, como parte do projeto da faculdade UERGS (2025)
