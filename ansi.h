//
// Created by Jannus on 05.07.2023.
//

#ifndef RL_ANSI_H
#define RL_ANSI_H

// SCI

#define ANSI_SCI_CUU "\e[A" // Cursor up
#define ANSI_SCI_CUO "\e[B" // Cursor down
#define ANSI_SCI_CUL "\e[C" // Cursor left
#define ANSI_SCI_CUR "\e[D" // Cursor right
#define ANSI_SCI_CNL "\e[E" // Cursor forward
#define ANSI_SCI_CPL "\e[F" // Cursor backward
#define ANSI_SCI_CHA "\e[G" // Horizontal absolute
#define ANSI_SCI_ED "\e[H" // Cursor position
#define ANSI_SCI_EL "\e[I" // Horizontal absolute
#define ANSI_SCI_SU "\e[J" // Scroll up
#define ANSI_SCI_SD "\e[K" // Scroll down
#define ANSI_SCI_CLS "\e[1;1H\e[2J"

// Regular text
#define ANSI_SGR_BLK "\e[0;30m"
#define ANSI_SGR_RED "\e[0;31m"
#define ANSI_SGR_GRN "\e[0;32m"
#define ANSI_SGR_YEL "\e[0;33m"
#define ANSI_SGR_BLU "\e[0;34m"
#define ANSI_SGR_MAG "\e[0;35m"
#define ANSI_SGR_CYN "\e[0;36m"
#define ANSI_SGR_WHT "\e[0;37m"

// Regular bold text
#define ANSI_SGR_BBLK "\e[1;30m"
#define ANSI_SGR_BRED "\e[1;31m"
#define ANSI_SGR_BGRN "\e[1;32m"
#define ANSI_SGR_BYEL "\e[1;33m"
#define ANSI_SGR_BBLU "\e[1;34m"
#define ANSI_SGR_BMAG "\e[1;35m"
#define ANSI_SGR_BCYN "\e[1;36m"
#define ANSI_SGR_BWHT "\e[1;37m"

// Regular underline text
#define ANSI_SGR_UBLK "\e[4;30m"
#define ANSI_SGR_URED "\e[4;31m"
#define ANSI_SGR_UGRN "\e[4;32m"
#define ANSI_SGR_UYEL "\e[4;33m"
#define ANSI_SGR_UBLU "\e[4;34m"
#define ANSI_SGR_UMAG "\e[4;35m"
#define ANSI_SGR_UCYN "\e[4;36m"
#define ANSI_SGR_UWHT "\e[4;37m"

// Regular background
#define ANSI_SGR_BLKB "\e[40m"
#define ANSI_SGR_REDB "\e[41m"
#define ANSI_SGR_GRNB "\e[42m"
#define ANSI_SGR_YELB "\e[43m"
#define ANSI_SGR_BLUB "\e[44m"
#define ANSI_SGR_MAGB "\e[45m"
#define ANSI_SGR_CYNB "\e[46m"
#define ANSI_SGR_WHTB "\e[47m"

// High intensty background
#define ANSI_SGR_BLKHB "\e[0;100m"
#define ANSI_SGR_REDHB "\e[0;101m"
#define ANSI_SGR_GRNHB "\e[0;102m"
#define ANSI_SGR_YELHB "\e[0;103m"
#define ANSI_SGR_BLUHB "\e[0;104m"
#define ANSI_SGR_MAGHB "\e[0;105m"
#define ANSI_SGR_CYNHB "\e[0;106m"
#define ANSI_SGR_WHTHB "\e[0;107m"

// High intensty text
#define ANSI_SGR_HBLK "\e[0;90m"
#define ANSI_SGR_HRED "\e[0;91m"
#define ANSI_SGR_HGRN "\e[0;92m"
#define ANSI_SGR_HYEL "\e[0;93m"
#define ANSI_SGR_HBLU "\e[0;94m"
#define ANSI_SGR_HMAG "\e[0;95m"
#define ANSI_SGR_HCYN "\e[0;96m"
#define ANSI_SGR_HWHT "\e[0;97m"

// Bold high intensity text
#define ANSI_SGR_BHBLK "\e[1;90m"
#define ANSI_SGR_BHRED "\e[1;91m"
#define ANSI_SGR_BHGRN "\e[1;92m"
#define ANSI_SGR_BHYEL "\e[1;93m"
#define ANSI_SGR_BHBLU "\e[1;94m"
#define ANSI_SGR_BHMAG "\e[1;95m"
#define ANSI_SGR_BHCYN "\e[1;96m"
#define ANSI_SGR_BHWHT "\e[1;97m"

// Reset
#define ANSI_SGR_RESET "\e[0m"

#endif //RL_ANSI_H
