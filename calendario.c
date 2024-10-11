struct evento{
    char nome[30];
    int dia, mes, ano;
    char local[30];
    int horario;
};

void menuCalendario(){
    printf("-----------------------------------------------\n");
    printf("Selecione qual funcionalidade deseja utilizar:\n");
    printf("1. Criar evento\n");
    printf("2. Excluir evento\n");
    printf("3. Editar dados de um evento\n");
    printf("0. Sair do aplicativo\n");
    printf("-----------------------------------------------\n");
    int esc;
    printf("Digite sua escolha: ");
    scanf("%d", &esc);
    switch(esc){
        case 1:
            printf("criar");
        case 2:
            printf("excluir");
        case 3:
            printf("editar");
        case 0:
            printf("sair");
    }
}