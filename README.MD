🧠 Nano VM - MIPS-based Virtual Machine

Uma pequena máquina virtual com arquitetura baseada em MIPS, desenvolvida para interpretar e executar programas simples com uma interface de terminal interativa (TUI).

📁 Estrutura do Projeto

```
vm/
├── main.c               # Orquestrador principal
├── loader.cpp           # Carrega programas e popula a memória
├── launch.c             # Executa as instruções da VM (core da CPU)
├── drop_down_menu.c     # Interface TUI para escolha de arquivos
├── dir_options.c        # Lê opções de diretório para o menu
├── instructions.h       # Define os opcodes e estrutura das instruções
├── launch.h             # Interface da função launch_program
└── programs/            # Programas escritos para rodar na VM
```

```

- Para gerar o executável, usar o comando "make" no terminal.
- Para executar, rodar, na pasta root do projeto: ./vm_launcher
- Se você não está no linux e não consegue rodar, bem feito. USE LINUX.


```

👨‍💻 Autor

Feito por Artur de Camargo, como parte do projeto da faculdade UERGS (2025)
