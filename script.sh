MY_ASM="$HOME/Documents/CoreWar/asm"
ASM="$HOME/Downloads/vm_champs/asm"

# while [[  ]] ; do

${MY_ASM} $1.s; ${ASM} $1.s
xxd $1.cor > a1 && xxd $1.cor > a2 && diff a1 a2

# end;
