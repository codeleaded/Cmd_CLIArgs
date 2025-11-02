#include "/home/codeleaded/System/Static/Library/CLIArgs.h"

#define CLIARG_VERSION              (CLIARG_START + 0)
#define CLIARG_LINKING              (CLIARG_START + 1)
#define CLIARG_OPTLVL               (CLIARG_START + 2)
#define CLIARG_TARGET               (CLIARG_START + 3)
#define CLIARG_INSTALL              (CLIARG_START + 4)

int main(int argc, const char *argv[]){
    CLIArgs args = CLIArgs_New((CLIArg[]){
        CLIArg_New(CLIARG_DFLAG,CLIARG_VERSION,"--version"),
        CLIArg_New(CLIARG_OPTION,CLIARG_LINKING,"-l"),
        CLIArg_New(CLIARG_OPTION,CLIARG_OPTLVL,"-O"),
        CLIArg_New(CLIARG_PFLAG,CLIARG_TARGET,"-t"),
        CLIArg_New(CLIARG_INST,CLIARG_INSTALL,"install"),
        CLIArg_Null()
    });

    CLIArgs_Parse(&args,"-O2 -lm -t ./data/Hello.txt --version");

    CStr optlvl = CLIArgs_Pop(&args,CLIARG_OPTLVL);
    if(optlvl){
        printf("OptLVL: %s\n",optlvl);
        CStr_Free(&optlvl);
    }

    CStr linking = NULL;
    while(linking = CLIArgs_Pop(&args,CLIARG_LINKING)){
        printf("Linking: %s\n",linking);
        CStr_Free(&linking);
    }

    CLIArgs_Free(&args);
    return 0;
}