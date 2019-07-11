#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define space 32
char mat[4][6];
int mem = 0, i, j, x, a[1001], a2[1001], initial_bet, sum_earn2 = 0, betpotential = 1;
char fr[3][6];
string seven(int pos) {
    if (pos == 1) return "#@@@@@@@@@@@@@@@@@@@@@@@@@   ";
    if (pos == 2) return "##.......................@   ";
    if (pos == 3) return "##`;;;;;;;;::::::::;;;;;#@   ";
    if (pos == 4) return "##`'''''';;;;;:::;;;;;;'#@   ";
    if (pos == 5) return "##`;'''''';;;;;:::;;;;;;#@   ";
    if (pos == 6) return "##`;;'''''';;;;;:::;;;;;#@   ";
    if (pos == 7) return "##`;;;''''';;;;;;:::;;;'#@   ";
    if (pos == 8) return "##'#++++++###+#+;;:::;; #@   ";
    if (pos == 9) return "##@@@@@@@@@@@@#';;;;:::'#@   ";
    if (pos == 10) return "            @@+';;;;;;::#@   ";
    if (pos == 11) return "           @@''''';;;;;#@@   ";
    if (pos == 12) return "          @@''''''';;;#@@    ";
    if (pos == 13) return "         @@';;'''''';#@@     ";
    if (pos == 14) return "        @@';;;;'''''#@@      ";
    if (pos == 15) return "       @@'::;;;;'''#@@       ";
    if (pos == 16) return "       @'::::;;;;;#@@        ";
    if (pos == 17) return "      @+;;::::;;;+#@         ";
    if (pos == 18) return "      @';;;:::;;;#@          ";
    if (pos == 19) return "     @';;;;::::+@@           ";
    if (pos == 20) return "     @+'';;;;:::#@           ";
    if (pos == 21) return "     @'''';;;;::#@           ";
    if (pos == 22) return "     @'@#########@           ";
    if (pos == 23) return "     @@@@@@@@@@@@@           ";
    return 0;
}
string orange(int pos) {
    if (pos == 1) return "            +;:;+            ";
    if (pos == 2) return "         ` :#@@@#: `         ";
    if (pos == 3) return "        :@@+:,,::+@@:        ";
    if (pos == 4) return "     '`@@:,,,,.,...,#@`;     ";
    if (pos == 5) return "    :;@::,,,..'`......@':    ";
    if (pos == 6) return "   ';@::,,....`........@:+   ";
    if (pos == 7) return "    @:::,....` .,,.....:@    ";
    if (pos == 8) return "  .@':::,,.,,,,,,,,....,+@,  ";
    if (pos == 9) return "   @::::,,,,,,,:,,,::,,:;@   ";
    if (pos == 10) return "  +@::::::,::,,,:::::::;;@:  ";
    if (pos == 11) return " '@+:::::,::::::::::::;;;##+ ";
    if (pos == 12) return " '@'::::::::::::::::::;;;##' ";
    if (pos == 13) return " '#+::::::::::::::::::;;;#'  ";
    if (pos == 14) return "  '@:::::::::::::::::;;;;@.@ ";
    if (pos == 15) return "   @:::::::::::::::::;;;;@   ";
    if (pos == 16) return "  ,@#:::::::::::::::;';;@++  ";
    if (pos == 17) return "    @;::;::::::::::;;;;+@    ";
    if (pos == 18) return "   +,@;;:;;::::::;;;;;'@     ";
    if (pos == 19) return "    '.@+;::;;;;;';;;;#@      ";
    if (pos == 20) return "       @@';;:;;;;;;+@# @     ";
    if (pos == 21) return "       : @@@#+'+#@@# ;       ";
    if (pos == 22) return "         '  ,:;:,  '         ";
    if (pos == 23) return "                             ";
    return 0;
}
string cherry(int pos) {
    if (pos == 1) return "                             ";
    if (pos == 2) return "       '.`,+       '@        ";
    if (pos == 3) return "      ,@@@@@.`@   ;;`.@      ";
    if (pos == 4) return "   :,@@;::,;@@ @#;:@@@       ";
    if (pos == 5) return "  ''@+';:.`,,#@ ':@'@' .'    ";
    if (pos == 6) return "   @++';:`.,;;@@:@'@@@@@@+,+ ";
    if (pos == 7) return "   @++'';;::;+'@@'@@'''+#@   ";
    if (pos == 8) return " ,@#++''';;;'++@+@#+##'+@    ";
    if (pos == 9) return " ,@#+++'+++''#@+@@@@##@@.+   ";
    if (pos == 10) return " '@@++@#;,:#@@#@@@@@@@@`+    ";
    if (pos == 11) return " @`@@#':,,,:;@@@,,,,:;@@`    ";
    if (pos == 12) return "   @#'',,,+++@#;,.,++''#@ @  ";
    if (pos == 13) return "  +@+'';:::'@@';;:::;'''@@:  ";
    if (pos == 14) return " .@#+''';;;;@+'';;;;;'+'+@   ";
    if (pos == 15) return "  @+++''''''@'''';;''''++@   ";
    if (pos == 16) return " `@#+++'''''@+''''''''+++@   ";
    if (pos == 17) return " ;@@++#++'++@@++''''++++#@`  ";
    if (pos == 18) return "   @#+++++++#@++++++++++@,   ";
    if (pos == 19) return "  ''@#+++++++@@++++++++@#,   ";
    if (pos == 20) return "   ,;@@#+++#@@@@@#++#@@;.    ";
    if (pos == 21) return "    + +@@@@@@`: '@@@@:       ";
    if (pos == 22) return "      +.    ;    ;,,;        ";
    if (pos == 23) return "                             ";
    return 0;
}
string star(int pos) {
    if (pos == 1) return "############## ##############";
    if (pos == 2) return "#############@+;#############";
    if (pos == 3) return "#############'#`#############";
    if (pos == 4) return "#####+''''''' ++''''''''#####";
    if (pos == 5) return "######''''''':+,;'''''''#####";
    if (pos == 6) return "######'''''';#:. '''''''#####";
    if (pos == 7) return "@#####'''''' +,,;'''''''#####";
    if (pos == 8) return "######''''''.+',;'''''''#####";
    if (pos == 9) return "######''''''@;;..`''''''#####";
    if (pos == 10) return "# `         +.,'::         ``";
    if (pos == 11) return "@@ @+';';'''#,,:,'''''''++:##";
    if (pos == 12) return "###';++:'+'''',,''''+:++#`###";
    if (pos == 13) return "####@ #++,; .,,,,,:;,#+,+####";
    if (pos == 14) return "@####+;:++.,.,,,,+.'+@`'#####";
    if (pos == 15) return "######'' #+;;,,,,.##,;''#####";
    if (pos == 16) return "######'''`;.,,;,,'::''''#####";
    if (pos == 17) return "######''',':,'`.::.:;'''#####";
    if (pos == 18) return "######'';+:;,:++.;`` '''#####";
    if (pos == 19) return "######'' ;,,++'#+,':+'''#####";
    if (pos == 20) return "######'''',++`'.#+':,:''#####";
    if (pos == 21) return "######',''+#`''';:++.`''#####";
    if (pos == 22) return "######+ '+;+++++++ #++++#####";
    if (pos == 23) return "#######+# #########,#;.######";
    return 0;
}
string plum(int pos) {
    if (pos == 1) return "                             ";
    if (pos == 2) return "                             ";
    if (pos == 3) return "                             ";
    if (pos == 4) return "          ``#@@@@@@@'        ";
    if (pos == 5) return "         ;@#';:,:'';#@:'     ";
    if (pos == 6) return "      :,@+''';.`:'''''@.     ";
    if (pos == 7) return "     `#@''''''''''''';+@ .'  ";
    if (pos == 8) return "    `@+''''''''''''';';@@@   ";
    if (pos == 9) return "   ;#+''''''''''''';;''@:'@: ";
    if (pos == 10) return "  @.#''''''''''''';;;''@@..  ";
    if (pos == 11) return "@#`@;''''''''''';;;;''@##    ";
    if (pos == 12) return " @,#'''''''''''''''''@'#:@   ";
    if (pos == 13) return " +@'''''''''+++++++++''@     ";
    if (pos == 14) return " ,@;''''''++++++++++''+@:    ";
    if (pos == 15) return " .@''''''++++++++##'''@      ";
    if (pos == 16) return " '@''+''+++++++#@#''+@.      ";
    if (pos == 17) return " @,@'''##+@#@@@@+++#@`       ";
    if (pos == 18) return "  .@#''+++++######@# @       ";
    if (pos == 19) return "    @@+'+++++##@@# '         ";
    if (pos == 20) return "    ,`@@@@@@@@#. +           ";
    if (pos == 21) return "         `                   ";
    if (pos == 22) return "                             ";
    if (pos == 23) return "                             ";
    return 0;
}
string grapes(int pos) {
    if (pos == 1) return "            ;@@ @+##;#; :,   ";
    if (pos == 2) return "            .@+@@+@#.;@+#+#: ";
    if (pos == 3) return "        +' .@#++##++#;+## ;. ";
    if (pos == 4) return "       ,#@@++#@++++#@##+#`@  ";
    if (pos == 5) return "        +@@++##@#@+@@@##`    ";
    if (pos == 6) return "       @;''@@@##+#+++@@`@    ";
    if (pos == 7) return "      #.,;'@'##+#+#++@+@'    ";
    if (pos == 8) return "     .@.`;'+@@#++#+@#++@`    ";
    if (pos == 9) return "     `@;''++@@###''@#++@.    ";
    if (pos == 10) return "    @`@''++@:;+#@+'++++#+    ";
    if (pos == 11) return "     @'#++#' :''##++++@@     ";
    if (pos == 12) return "    @:`##+#;:;'+@'@@@@+#,    ";
    if (pos == 13) return "   :@;:;'#@+'''+@:,;'++++@   ";
    if (pos == 14) return "   :@'''++#@'+++@''''+++;@   ";
    if (pos == 15) return "   .@++++@;'@+++@+''+++@     ";
    if (pos == 16) return "  ;@;@++@`,'+;@@+@++++#;     ";
    if (pos == 17) return "   +`;@@',:'+;''++#@@@`+     ";
    if (pos == 18) return " @';:;'#';''@''++++@ +       ";
    if (pos == 19) return "  +'''+#+''+@++++++@'        ";
    if (pos == 20) return "  .#++++@++++@#++#@          ";
    if (pos == 21) return "  ,@+++++@+++#@@@,.          ";
    if (pos == 22) return "    @#+#@`+@@,,              ";
    if (pos == 23) return "        .#@+                 ";
    return 0;
}
string lemon(int pos) {
    if (pos == 1) return "             ;  ,', '        ";
    if (pos == 2) return "            .@@@@@@@+ @      ";
    if (pos == 3) return "         `,@@#:,,,;@@@. .    ";
    if (pos == 4) return "       + @@;,,,,,,,,#@@@@`   ";
    if (pos == 5) return "      ,;@+,,,,,,,,,,,,+#@@   ";
    if (pos == 6) return "     `#@,,,,,,,,,,,,,,,,+@`  ";
    if (pos == 7) return "    .#@,,,,,,,,,,,,,,,,,;@`  ";
    if (pos == 8) return "   ''@,,,,,,,,,,,,,,,,,,@@:  ";
    if (pos == 9) return "  @`@,,,,,,,,,,,,,,,,,,,@:@  ";
    if (pos == 10) return "  ,@#,,,,,,,,,,,,,,,,,,,@    ";
    if (pos == 11) return "   @,,,,,,,,.```.,,,,,,,@    ";
    if (pos == 12) return "  `@,,,,,,,,`  `.,,,,,,,@    ";
    if (pos == 13) return "  ,@,,,,,,,,```.,,,,,,,:@    ";
    if (pos == 14) return "  .@,,,,,,,,,,,,,,,,;,,@@:   ";
    if (pos == 15) return "   @:,,,,,,,,,,,,,,::::@     ";
    if (pos == 16) return "   @,:,,,,,,,,,,,,:;:,@+     ";
    if (pos == 17) return " @:@:::::,,,,,,,,;;,,@#`     ";
    if (pos == 18) return " ;@+:::;:::,::;;;,::@'.      ";
    if (pos == 19) return " :@@::::;;;;;;;;::'@`;       ";
    if (pos == 20) return "  :@@#+:::::::::;@#          ";
    if (pos == 21) return "  ,,'@@@@'::::#@@ :          ";
    if (pos == 22) return "     : '@@@@@@# .            ";
    if (pos == 23) return "          ,.  '              ";
    return 0;
}
string watermelon(int pos) {
    if (pos == 1) return "          ,   .+              ";
    if (pos == 2) return "        .:@##@@@: '           ";
    if (pos == 3) return "        @:``.`,@'@#`;         ";
    if (pos == 4) return "       @.`;+',.`@,:@#         ";
    if (pos == 5) return "     :#.:',:,,``,',:'@,;      ";
    if (pos == 6) return "    @,+:;,,,..,+.@#+,,@':     ";
    if (pos == 7) return "    .@`',:,,,,,:,:+#+;,@''    ";
    if (pos == 8) return "     +,::,,,,,,,'`#.:#+.@.@   ";
    if (pos == 9) return "    +`;:.`,:,,,,'`@...##,@`   ";
    if (pos == 10) return "   :@`;:,:,+,,::'`@....:+#:@  ";
    if (pos == 11) return "   `@.;::'',::::'.@,,,,..,@;  ";
    if (pos == 12) return "    @;;::::;,:::+`@#;::,.;@`  ";
    if (pos == 13) return "    @,;::;;:::::+`@@@@#+:`# @ ";
    if (pos == 14) return "    @.;;;:::::::'.#++##:;`@.  ";
    if (pos == 15) return " .  @`';;;:::::;,@'++'''';@'  ";
    if (pos == 16) return " '  @`';;;;;;;;+`@++++'+;@,@  ";
    if (pos == 17) return "   @.+.';;;;;;'.@++#@@@++@.   ";
    if (pos == 18) return "    `@`.'+;;;+.'#@@@@@++@     ";
    if (pos == 19) return "     `@``.'+.`:@###+++@@.+    ";
    if (pos == 20) return "     +,@.`.``+@#####@@@ @     ";
    if (pos == 21) return "        @@@@@@@@@@@@@`;@      ";
    if (pos == 22) return "        ; ,+#@@@#'. ;@        ";
    if (pos == 23) return "         @##+'''+@@           ";
    return 0;
}
string zero(int pos) {
    if (pos == 1) return " _______ ";
    if (pos == 2) return "|  _    |";
    if (pos == 3) return "| | |   |";
    if (pos == 4) return "| | |   |";
    if (pos == 5) return "| |_|   |";
    if (pos == 6) return "|       |";
    if (pos == 7) return "|_______|";
    return 0;
}
string one(int pos) {
    if (pos == 1) return " ____ ";
    if (pos == 2) return "|    |";
    if (pos == 3) return " |   |";
    if (pos == 4) return " |   |";
    if (pos == 5) return " |   |";
    if (pos == 6) return " |   |";
    if (pos == 7) return " |___|";
    return 0;
}
string two(int pos) {
    if (pos == 1) return " _______ ";
    if (pos == 2) return "|       |";
    if (pos == 3) return "|____   |";
    if (pos == 4) return " ____|  |";
    if (pos == 5) return "| ______|";
    if (pos == 6) return "| |_____ ";
    if (pos == 7) return "|_______|";
    return 0;
}
string three(int pos) {
    if (pos == 1) return " _______ ";
    if (pos == 2) return "|       |";
    if (pos == 3) return "|___    |";
    if (pos == 4) return " ___|   |";
    if (pos == 5) return "|___    |";
    if (pos == 6) return " ___|   |";
    if (pos == 7) return "|_______|";
    return 0;
}
string four(int pos) {
    if (pos == 1) return " _   ___ ";
    if (pos == 2) return "| | |   |";
    if (pos == 3) return "| |_|   |";
    if (pos == 4) return "|       |";
    if (pos == 5) return "|___    |";
    if (pos == 6) return "    |   |";
    if (pos == 7) return "    |___|";
    return 0;
}
string five(int pos) {
    if (pos == 1) return " _______ ";
    if (pos == 2) return "|       |";
    if (pos == 3) return "|   ____|";
    if (pos == 4) return "|  |____ ";
    if (pos == 5) return "|_____  |";
    if (pos == 6) return " _____| |";
    if (pos == 7) return "|_______|";
    return 0;
}
string six(int pos) {
    if (pos == 1) return " ___     ";
    if (pos == 2) return "|   |    ";
    if (pos == 3) return "|   |___ ";
    if (pos == 4) return "|    _  |";
    if (pos == 5) return "|   | | |";
    if (pos == 6) return "|   |_| |";
    if (pos == 7) return "|_______|";
    return 0;
}
string seven2(int pos) {
    if (pos == 1) return " _______ ";
    if (pos == 2) return "|       |";
    if (pos == 3) return "|___    |";
    if (pos == 4) return "    |   |";
    if (pos == 5) return "    |   |";
    if (pos == 6) return "    |   |";
    if (pos == 7) return "    |___|";
    return 0;
}
string eight(int pos) {
    if (pos == 1) return "  _____  ";
    if (pos == 2) return " |  _  | ";
    if (pos == 3) return " | |_| | ";
    if (pos == 4) return "|   _   |";
    if (pos == 5) return "|  | |  |";
    if (pos == 6) return "|  |_|  |";
    if (pos == 7) return "|_______|";
    return 0;
}
string nine(int pos) {
    if (pos == 1) return " _______ ";
    if (pos == 2) return "|  _    |";
    if (pos == 3) return "| | |   |";
    if (pos == 4) return "| |_|   |";
    if (pos == 5) return "|___    |";
    if (pos == 6) return "    |   |";
    if (pos == 7) return "    |___|";
    return 0;
}
string credit(int pos) {
    if (pos == 1) return " _______  ______    _______  ______   ___   _______  ___  ";
    if (pos == 2) return "|       ||    _ |  |       ||      | |   | |       ||   | ";
    if (pos == 3) return "|       ||   | ||  |    ___||  _    ||   | |_     _||___| ";
    if (pos == 4) return "|       ||   |_||_ |   |___ | | |   ||   |   |   |   ___  ";
    if (pos == 5) return "|      _||    __  ||    ___|| |_|   ||   |   |   |  |   | ";
    if (pos == 6) return "|     |_ |   |  | ||   |___ |       ||   |   |   |  |___| ";
    if (pos == 7) return "|_______||___|  |_||_______||______| |___|   |___|        ";
    return 0;
}
string bet(int pos) {
    if (pos == 1) return " _______  _______  _______  ___  ";
    if (pos == 2) return "|  _    ||       ||       ||   | ";
    if (pos == 3) return "| |_|   ||    ___||_     _||___| ";
    if (pos == 4) return "|       ||   |___   |   |   ___  ";
    if (pos == 5) return "|  _   | |    ___|  |   |  |   | ";
    if (pos == 6) return "| |_|   ||   |___   |   |  |___| ";
    if (pos == 7) return "|_______||_______|  |___|        ";
    return 0;
}
string last_win(int pos) {
    if (pos == 1) return " ___      _______  _______  _______    _     _  ___   __    _  ___  ";
    if (pos == 2) return "|   |    |   _   ||       ||       |  | | _ | ||   | |  |  | ||   | ";
    if (pos == 3) return "|   |    |  |_|  ||  _____||_     _|  | || || ||   | |   |_| ||___| ";
    if (pos == 4) return "|   |    |       || |_____   |   |    |       ||   | |       | ___  ";
    if (pos == 5) return "|   |___ |       ||_____  |  |   |    |       ||   | |  _    ||   | ";
    if (pos == 6) return "|       ||   _   | _____| |  |   |    |   _   ||   | | | |   ||___| ";
    if (pos == 7) return "|_______||__| |__||_______|  |___|    |__| |__||___| |_|  |__|      ";
    return 0;
}
void outwithyou() {
   if (mat[i][j] == 'W') cout << watermelon(mem) << "   ";
   if (mat[i][j] == 'P') cout << plum(mem) << "   ";
   if (mat[i][j] == 'L') cout << lemon(mem) << "   ";
   if (mat[i][j] == 'S') cout << star(mem) << "   ";
   if (mat[i][j] == 'G') cout << grapes(mem) << "   ";
   if (mat[i][j] == 'O') cout << orange(mem) << "   ";
   if (mat[i][j] == 'C') cout << cherry(mem) << "   ";
   if (mat[i][j] == '7') cout << seven(mem) << "   ";
}
void outwithyoutoo() {
   if (a[j] == 1) cout << one(i) << " ";
   if (a[j] == 2) cout << two(i) << " ";
   if (a[j] == 3) cout << three(i) << " ";
   if (a[j] == 4) cout << four(i) << " ";
   if (a[j] == 5) cout << five(i) << " ";
   if (a[j] == 6) cout << six(i) << " ";
   if (a[j] == 7) cout << seven2(i) << " ";
   if (a[j] == 8) cout << eight(i) << " ";
   if (a[j] == 9) cout << nine(i) << " ";
   if (a[j] == 0) cout << zero(i) << " ";
}
void outwithyouthree() {
   if (a2[j] == 1) cout << one(i) << " ";
   if (a2[j] == 2) cout << two(i) << " ";
   if (a2[j] == 3) cout << three(i) << " ";
   if (a2[j] == 4) cout << four(i) << " ";
   if (a2[j] == 5) cout << five(i) << " ";
   if (a2[j] == 6) cout << six(i) << " ";
   if (a2[j] == 7) cout << seven2(i) << " ";
   if (a2[j] == 8) cout << eight(i) << " ";
   if (a2[j] == 9) cout << nine(i) << " ";
   if (a2[j] == 0) cout << zero(i) << " ";
}
int chart(int combo, char given, int bet) {
    int total = 0;
    if ((given == 'W') or (given == 'G')) {
        if (combo == 3) total += (bet*10);
        if (combo == 4) total += (bet*40);
        if (combo == 5) total += (bet*100);
    }
    if ((given == 'P') or (given == 'O') or (given == 'L') or (given == 'C')) {
        if (combo == 3) total += (bet*4);
        if (combo == 4) total += (bet*10);
        if (combo == 5) total += (bet*40);
    }
    if (given == '7') {
        if (combo == 3) total += (bet*20);
        if (combo == 4) total += (bet*200);
        if (combo == 5) total += (bet*1000);
    }
    if (given == 'C') {
        if (combo == 2) total += (initial_bet*1);
    }
    return total;
}
int toggle(int pos) {
    if (pos == 1) return 20;
    if (pos == 2) return 25;
    if (pos == 3) return 40;
    if (pos == 4) return 50;
    if (pos == 5) return 75;
    if (pos == 6) return 100;
    if (pos == 7) return 150;
    if (pos == 8) return 200;
    if (pos == 9) return 250;
    if (pos == 10) return 400;
    if (pos == 11) return 500;
    if (pos == 12) return 750;
    if (pos == 13) return 1000;
    if (pos == 14) return 1500;
    if (pos == 15) return 2000;
    if (pos == 16) return 2500;
    if (pos == 17) return 4000;
    if (pos == 18) return 5000;
    if (pos == 19) return 7500;
    if (pos == 20) return 10000;
}
int main() {
    srand(time(NULL));
    map <int, char> random_symb;
    random_symb[0] = 'W';
    random_symb[1] = 'P';
    random_symb[2] = 'L';
    random_symb[3] = 'S';
    random_symb[4] = 'G';
    random_symb[5] = 'O';
    random_symb[6] = 'C';
    random_symb[7] = '7';
    system("color 70");
    cout << " _______  ___   _______  _______  ___      ___   __    _  _______    __   __  _______  _______ " << endl;
    cout << "|       ||   | |       ||       ||   |    |   | |  |  | ||       |  |  | |  ||       ||       |" << endl;
    cout << "|  _____||   | |____   ||____   ||   |    |   | |   |_| ||    ___|  |  |_|  ||   _   ||_     _|" << endl;
    cout << "| |_____ |   |  ____|  | ____|  ||   |    |   | |       ||   | __   |       ||  | |  |  |   |  " << endl;
    cout << "|_____  ||   | | ______|| ______||   |___ |   | |  _    ||   ||  |  |       ||  |_|  |  |   |  " << endl;
    cout << " _____| ||   | | |_____ | |_____ |       ||   | | | |   ||   |_| |  |   _   ||       |  |   |  " << endl;
    cout << "|_______||___| |_______||_______||_______||___| |_|  |__||_______|  |__| |__||_______|  |___|  " << endl;
    cout << endl << endl << endl;
    cout << endl << endl << endl;
    cout << endl << endl << endl;
    cout << endl << endl << endl;
    cout << " _______  ______    _______  _______  _______           _______  _______  _______  _______  _______           _______  _______    _______  _______  _______ " << endl;
    cout << "|       ||    _ |  |       ||       ||       |         |       ||       ||   _   ||       ||       |         |       ||       |  |  _    ||       ||       |" << endl;
    cout << "|    _  ||   | ||  |    ___||  _____||  _____|   ____  |  _____||    _  ||  |_|  ||       ||    ___| ____    |_     _||   _   |  | |_|   ||    ___||_     _|" << endl;
    cout << "|   |_| ||   |_||_ |   |___ | |_____ | |_____   |____| | |_____ |   |_| ||       ||       ||   |___ |____|     |   |  |  | |  |  |       ||   |___   |   |  " << endl;
    cout << "|    ___||    __  ||    ___||_____  ||_____  |         |_____  ||    ___||       ||      _||    ___|           |   |  |  |_|  |  |  _   | |    ___|  |   |  " << endl;
    cout << "|   |    |   |  | ||   |___  _____| | _____| |          _____| ||   |    |   _   ||     |_ |   |___            |   |  |       |  | |_|   ||   |___   |   |  " << endl;
    cout << "|___|    |___|  |_||_______||_______||_______|         |_______||___|    |__| |__||_______||_______|           |___|  |_______|  |_______||_______|  |___|  " << endl;
    cout << endl << endl << endl;
    cout << " _______  ______    _______  _______  _______                          _______  _______    ___   __    _  _______          _______  _______  _______                " << endl;
    cout << "|       ||    _ |  |       ||       ||       |                        |       ||       |  |   | |  |  | ||       |        |  _    ||       ||       |               " << endl;
    cout << "|    _  ||   | ||  |    ___||  _____||  _____|   ____         ____    |_     _||   _   |  |   | |   |_| ||       |        | |_|   ||    ___||_     _|               " << endl;
    cout << "|   |_| ||   |_||_ |   |___ | |_____ | |_____   |____|       |____|     |   |  |  | |  |  |   | |       ||       |        |       ||   |___   |   |                 " << endl;
    cout << "|    ___||    __  ||    ___||_____  ||_____  |          ___             |   |  |  |_|  |  |   | |  _    ||      _| ___    |  _   | |    ___|  |   |                 " << endl;
    cout << "|   |    |   |  | ||   |___  _____| | _____| |         |   |            |   |  |       |  |   | | | |   ||     |_ |   |   | |_|   ||   |___   |   |                 " << endl;
    cout << "|___|    |___|  |_||_______||_______||_______|         |___|            |___|  |_______|  |___| |_|  |__||_______||___|   |_______||_______|  |___|                 " << endl;
    cout << endl << endl << endl;
    cout << " _______  ______    _______  _______  _______                          _______  _______    ______   _______  _______          _______  _______  _______             " << endl;
    cout << "|       ||    _ |  |       ||       ||       |                        |       ||       |  |      | |       ||       |        |  _    ||       ||       |            " << endl;
    cout << "|    _  ||   | ||  |    ___||  _____||  _____|   ____         ____    |_     _||   _   |  |  _    ||    ___||       |        | |_|   ||    ___||_     _|            " << endl;
    cout << "|   |_| ||   |_||_ |   |___ | |_____ | |_____   |____|       |____|     |   |  |  | |  |  | | |   ||   |___ |       |        |       ||   |___   |   |              " << endl;
    cout << "|    ___||    __  ||    ___||_____  ||_____  |          ___             |   |  |  |_|  |  | |_|   ||    ___||      _| ___    |  _   | |    ___|  |   |              " << endl;
    cout << "|   |    |   |  | ||   |___  _____| | _____| |         |_  |            |   |  |       |  |       ||   |___ |     |_ |   |   | |_|   ||   |___   |   |              " << endl;
    cout << "|___|    |___|  |_||_______||_______||_______|           |_|            |___|  |_______|  |______| |_______||_______||___|   |_______||_______|  |___|              " << endl;
    cout << endl << endl << endl;
    cout << " _______  ______    _______  _______  _______           _______           _______  _______  ______      _______  ______    _______  ______   ___   _______  _______ " << endl;
    cout << "|       ||    _ |  |       ||       ||       |         |       |         |       ||       ||    _ |    |       ||    _ |  |       ||      | |   | |       ||       |" << endl;
    cout << "|    _  ||   | ||  |    ___||  _____||  _____|   ____  |       | ____    |    ___||   _   ||   | ||    |       ||   | ||  |    ___||  _    ||   | |_     _||  _____|" << endl;
    cout << "|   |_| ||   |_||_ |   |___ | |_____ | |_____   |____| |       ||____|   |   |___ |  | |  ||   |_||_   |       ||   |_||_ |   |___ | | |   ||   |   |   |  | |_____ " << endl;
    cout << "|    ___||    __  ||    ___||_____  ||_____  |         |      _|         |    ___||  |_|  ||    __  |  |      _||    __  ||    ___|| |_|   ||   |   |   |  |_____  |" << endl;
    cout << "|   |    |   |  | ||   |___  _____| | _____| |         |     |_          |   |    |       ||   |  | |  |     |_ |   |  | ||   |___ |       ||   |   |   |   _____| |" << endl;
    cout << "|___|    |___|  |_||_______||_______||_______|         |_______|         |___|    |_______||___|  |_|  |_______||___|  |_||_______||______| |___|   |___|  |_______|" << endl;
    cout << endl << endl << endl;
    cout << " _______  ______    _______  _______  _______           _______  _______  _______           _______  _______    _______  __   __  ___   _______ " << endl;
    cout << "|       ||    _ |  |       ||       ||       |         |       ||       ||       |         |       ||       |  |       ||  |_|  ||   | |       |" << endl;
    cout << "|    _  ||   | ||  |    ___||  _____||  _____|   ____  |    ___||  _____||       | ____    |_     _||   _   |  |    ___||       ||   | |_     _|" << endl;
    cout << "|   |_| ||   |_||_ |   |___ | |_____ | |_____   |____| |   |___ | |_____ |       ||____|     |   |  |  | |  |  |   |___ |       ||   |   |   |  " << endl;
    cout << "|    ___||    __  ||    ___||_____  ||_____  |         |    ___||_____  ||      _|           |   |  |  |_|  |  |    ___| |     | |   |   |   |  " << endl;
    cout << "|   |    |   |  | ||   |___  _____| | _____| |         |   |___  _____| ||     |_            |   |  |       |  |   |___ |   _   ||   |   |   |  " << endl;
    cout << "|___|    |___|  |_||_______||_______||_______|         |_______||_______||_______|           |___|  |_______|  |_______||__| |__||___|   |___|  " << endl;
    cout << endl << endl << endl;
    cout << " ______    _______  _______  _______  __   __  __   __  _______  __    _  ______   _______  ______     _______  _______  __    _  _______  ___                      " << endl;
    cout << "|    _ |  |       ||       ||       ||  |_|  ||  |_|  ||       ||  |  | ||      | |       ||      |   |       ||       ||  |  | ||       ||   |                     " << endl;
    cout << "|   | ||  |    ___||       ||   _   ||       ||       ||    ___||   |_| ||  _    ||    ___||  _    |  |    ___||   _   ||   |_| ||_     _||___|                     " << endl;
    cout << "|   |_||_ |   |___ |       ||  | |  ||       ||       ||   |___ |       || | |   ||   |___ | | |   |  |   |___ |  | |  ||       |  |   |   ___                      " << endl;
    cout << "|    __  ||    ___||      _||  |_|  ||       ||       ||    ___||  _    || |_|   ||    ___|| |_|   |  |    ___||  |_|  ||  _    |  |   |  |   |                     " << endl;
    cout << "|   |  | ||   |___ |     |_ |       || ||_|| || ||_|| ||   |___ | | |   ||       ||   |___ |       |  |   |    |       || | |   |  |   |  |___|                     " << endl;
    cout << "|___|  |_||_______||_______||_______||_|   |_||_|   |_||_______||_|  |__||______| |_______||______|   |___|    |_______||_|  |__|  |___|                            " << endl;
    cout << endl << endl << endl;
    cout << " _______  _______  __    _  _______  _______  ___      _______  _______          _______                                                                            " << endl;
    cout << "|       ||       ||  |  | ||       ||       ||   |    |   _   ||       |        |       |                                                                           " << endl;
    cout << "|       ||   _   ||   |_| ||  _____||   _   ||   |    |  |_|  ||  _____|        |___    |                                                                           " << endl;
    cout << "|       ||  | |  ||       || |_____ |  | |  ||   |    |       || |_____             |   |                                                                           " << endl;
    cout << "|      _||  |_|  ||  _    ||_____  ||  |_|  ||   |___ |       ||_____  | ___        |   |                                                                           " << endl;
    cout << "|     |_ |       || | |   | _____| ||       ||       ||   _   | _____| ||_  |       |   |                                                                           " << endl;
    cout << "|_______||_______||_|  |__||_______||_______||_______||__| |__||_______|  |_|       |___|                                                                           " << endl;
    if (getch()) {
        system("cls");
        for (j = 1; j <= 23; j++) {
            for (i = 1; i <= 5; i++) {
                cout << star(j) << "    ";
                mat[1][i] = 'S';
            }
            cout << endl;
        }
        cout << endl << endl;
        for (j = 1; j <= 23; j++) {
            for (i = 1; i <= 5; i++) {
                cout << seven(j) << "    ";
                mat[2][i] = '7';
            }
            cout << endl;
        }
        cout << endl << endl;
        for (j = 1; j <= 23; j++) {
            for (i = 1; i <= 5; i++) {
                cout << star(j) << "    ";
                mat[3][i] = 'S';
            }
            cout << endl;
        }
        int gr = 0;
        int initial_credit = 1000;
        initial_bet = toggle(betpotential);
        for (x = 1; x <= initial_credit; x *= 10) gr++;
        x /= 10; gr--;
        i = 0;
        while (x > 0) {
            a[++i] = initial_credit / x % 10;
            x /= 10;
            if (x == 0) a[++i] = initial_credit % 10;
        }
        for (i = 1; i <= 7; i++) {
            cout << credit(i) << " ";
            for (j = 1; j <= gr+1; j++) {
                outwithyoutoo();
            }
            cout << endl;
        }
        gr = 0;
        for (x = 1; x <= initial_bet; x *= 10) gr++;
        x /= 10; gr--;
        i = 0;
        while (x > 0) {
            a[++i] = initial_bet / x % 10;
            x /= 10;
            if (x == 0) a[++i] = initial_bet % 10;
        }
        for (i = 1; i <= 7; i++) {
            cout << bet(i) << " ";
            for (j = 1; j <= gr+1; j++) {
                outwithyoutoo();
            }
            cout << endl;
        }
        gr = 0;
        for (x = 1; x <= sum_earn2; x *= 10) gr++;
        x /= 10; gr--;
        i = 0;
        if (x == 0) {
            a2[1] = 0;
            gr++;
        }
        while (x > 0) {
            a2[++i] = sum_earn2 / x % 10;
            x /= 10;
            if (x == 0) a2[++i] = sum_earn2 % 10;
        }
        for (i = 1; i <= 7; i++) {
            cout << last_win(i) << " ";
            for (j = 1; j <= gr+1; j++) {
                outwithyouthree();
            }
            cout << endl;
        }
        cout << endl << endl;
        while (1) {
            initial_bet = toggle(betpotential);
            mem = 0;
            int key = getch();
            if ((key == space) and (initial_bet <= initial_credit)) {
                system("cls");
                int l = 1, b = 0;
                while (1) {
                    if (l == 4) break;
                    int dice1 = rand();
                    if ((dice1 % 8 == 3) or (dice1 % 8 == 7))
                        dice1 = rand();
                    char dice2 = random_symb[dice1%8];
                    mat[l][++b] = dice2;
                    if (b == 5) {
                        l++;
                        b = 0;
                    }
                }
                for (i = 1; i <= 3; i++) {
                    for (mem = 1; mem <= 23; mem++) {
                        for (j = 1; j <= 5; j++)
                            outwithyou();
                        cout << endl;
                    }
                    cout << endl;
                }
                int consq, sum_earn = 0, scatter = 0;
                for (i = 1; i <= 3; i++)
                    for (j = 1; j <= 5; j++)
                        if (mat[i][j] == 'S') scatter++;
                for (i = 1; i <= 3; i++) {
                    consq = 0;
                    for (j = 1; j <= 5; j++) {
                        if (mat[i][j] == mat[i][1]) consq++;
                        else {
                            if (consq >= 2) sum_earn += chart(consq, mat[i][1], initial_bet);
                            break;
                        }
                        if (j == 5) sum_earn += chart(consq, mat[i][1], initial_bet);
                    }
                }
                fr[1][1] = mat[1][1]; fr[2][1] = mat[3][1];
                fr[1][2] = mat[2][2]; fr[2][2] = mat[2][2];
                fr[1][3] = mat[3][3]; fr[2][3] = mat[1][3];
                fr[1][4] = mat[2][4]; fr[2][4] = mat[2][4];
                fr[1][5] = mat[1][5]; fr[2][5] = mat[3][5];
                int gr = 0;
                for (i = 1; i <= 2; i++) {
                    consq = 0;
                    for (j = 1; j <= 5; j++) {
                        if (fr[i][j] == fr[i][1]) consq++;
                        else {
                            if (consq >= 2) sum_earn += chart(consq, fr[i][1], initial_bet);
                            break;
                        }
                            if (j == 5) sum_earn += chart(consq, fr[i][1], initial_bet);
                    }
                }
                if (scatter >= 3) {
                    if (scatter == 3)
                        sum_earn += initial_bet*2;
                    if (scatter == 4)
                        sum_earn += initial_bet*10;
                    if (scatter == 5)
                        sum_earn += initial_bet*50;
                }
                initial_credit -= initial_bet;
                initial_credit += sum_earn;
                if (sum_earn > 0) sum_earn2 = sum_earn;
                if (initial_credit >= 20) {
                    for (x = 1; x <= initial_credit; x *= 10) gr++;
                    x /= 10; gr--;
                    i = 0;
                    while (x > 0) {
                        a[++i] = initial_credit / x % 10;
                        x /= 10;
                        if (x == 0) a[++i] = initial_credit % 10;
                    }
                    for (i = 1; i <= 7; i++) {
                        cout << credit(i) << " ";
                        for (j = 1; j <= gr+1; j++) {
                            outwithyoutoo();
                        }
                        cout << endl;
                    }
                }
                else {
                    system("cls");
                    cout << "        _______  _______  __   __  _______    _______  __   __  _______  ______          " << endl;
                    cout << "       |       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |         " << endl;
                    cout << " ____  |    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||   ____  " << endl;
                    cout << "|____| |   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ |____| " << endl;
                    cout << "       |   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |       " << endl;
                    cout << "       |   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |       " << endl;
                    cout << "       |_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|       " << endl;
                    break;
                }
                gr = 0;
                for (x = 1; x <= initial_bet; x *= 10) gr++;
                x /= 10; gr--;
                i = 0;
                while (x > 0) {
                    a[++i] = initial_bet / x % 10;
                    x /= 10;
                    if (x == 0) a[++i] = initial_bet % 10;
                }
                for (i = 1; i <= 7; i++) {
                    cout << bet(i) << " ";
                    for (j = 1; j <= gr+1; j++) {
                        outwithyoutoo();
                    }
                    cout << endl;
                }
                gr = 0;
                for (x = 1; x <= sum_earn2; x *= 10) gr++;
                x /= 10; gr--;
                i = 0;
                if (x == 0) {
                    a2[1] = 0;
                    gr++;
                }
                while (x > 0) {
                    a2[++i] = sum_earn2 / x % 10;
                    x /= 10;
                    if (x == 0) a2[++i] = sum_earn2 % 10;
                }
                for (i = 1; i <= 7; i++) {
                    cout << last_win(i) << " ";
                    for (j = 1; j <= gr+1; j++) {
                        outwithyouthree();
                    }
                    cout << endl;
                }
            }
            if (key == '.') {
                system("cls");
                betpotential++;
                if (betpotential > 20) betpotential = 1;
                initial_bet = toggle(betpotential);
                for (i = 1; i <= 3; i++) {
                    for (mem = 1; mem <= 23; mem++) {
                        for (j = 1; j <= 5; j++)
                            outwithyou();
                            cout << endl;
                    }
                    cout << endl;
                }
                int gr = 0;
                for (x = 1; x <= initial_credit; x *= 10) gr++;
                x /= 10; gr--;
                i = 0;
                while (x > 0) {
                    a[++i] = initial_credit / x % 10;
                    x /= 10;
                    if (x == 0) a[++i] = initial_credit % 10;
                }
                for (i = 1; i <= 7; i++) {
                    cout << credit(i) << " ";
                    for (j = 1; j <= gr+1; j++) {
                        outwithyoutoo();
                    }
                    cout << endl;
                }
                gr = 0;
                for (x = 1; x <= initial_bet; x *= 10) gr++;
                x /= 10; gr--;
                i = 0;
                while (x > 0) {
                    a[++i] = initial_bet / x % 10;
                    x /= 10;
                    if (x == 0) a[++i] = initial_bet % 10;
                }
                for (i = 1; i <= 7; i++) {
                    cout << bet(i) << " ";
                    for (j = 1; j <= gr+1; j++) {
                        outwithyoutoo();
                    }
                    cout << endl;
                }
                gr = 0;
                for (x = 1; x <= sum_earn2; x *= 10) gr++;
                x /= 10; gr--;
                i = 0;
                if (x == 0) {
                    a2[1] = 0;
                    gr++;
                }
                while (x > 0) {
                    a2[++i] = sum_earn2 / x % 10;
                    x /= 10;
                    if (x == 0) a2[++i] = sum_earn2 % 10;
                }
                for (i = 1; i <= 7; i++) {
                    cout << last_win(i) << " ";
                    for (j = 1; j <= gr+1; j++) {
                        outwithyouthree();
                    }
                    cout << endl;
                }
            }
            if (key == ',') {
                system("cls");
                betpotential--;
                if (betpotential < 1) betpotential = 20;
                initial_bet = toggle(betpotential);
                for (i = 1; i <= 3; i++) {
                    for (mem = 1; mem <= 23; mem++) {
                        for (j = 1; j <= 5; j++)
                            outwithyou();
                        cout << endl;
                    }
                    cout << endl;
                }
                int gr = 0;
                for (x = 1; x <= initial_credit; x *= 10) gr++;
                x /= 10; gr--;
                i = 0;
                while (x > 0) {
                    a[++i] = initial_credit / x % 10;
                    x /= 10;
                    if (x == 0) a[++i] = initial_credit % 10;
                }
                for (i = 1; i <= 7; i++) {
                    cout << credit(i) << " ";
                    for (j = 1; j <= gr+1; j++) {
                        outwithyoutoo();
                    }
                    cout << endl;
                }
                gr = 0;
                for (x = 1; x <= initial_bet; x *= 10) gr++;
                x /= 10; gr--;
                i = 0;
                while (x > 0) {
                    a[++i] = initial_bet / x % 10;
                    x /= 10;
                    if (x == 0) a[++i] = initial_bet % 10;
                }
                for (i = 1; i <= 7; i++) {
                    cout << bet(i) << " ";
                    for (j = 1; j <= gr+1; j++) {
                        outwithyoutoo();
                    }
                    cout << endl;
                }
                gr = 0;
                for (x = 1; x <= sum_earn2; x *= 10) gr++;
                x /= 10; gr--;
                i = 0;
                if (x == 0) {
                    a2[1] = 0;
                    gr++;
                }
                while (x > 0) {
                    a2[++i] = sum_earn2 / x % 10;
                    x /= 10;
                    if (x == 0) a2[++i] = sum_earn2 % 10;
                }
                for (i = 1; i <= 7; i++) {
                    cout << last_win(i) << " ";
                    for (j = 1; j <= gr+1; j++) {
                        outwithyouthree();
                    }
                    cout << endl;
                }
            }
            if (key == 27) return 0;
            if (key == 'c') {
                system("cls");
                cout << " __   __  _______  ______   _______    _______  __   __  ___                                                                                            " << endl;
                cout << "|  |_|  ||   _   ||      | |       |  |  _    ||  | |  ||   |                                                                                           " << endl;
                cout << "|       ||  |_|  ||  _    ||    ___|  | |_|   ||  |_|  ||___|                                                                                           " << endl;
                cout << "|       ||       || | |   ||   |___   |       ||       | ___                                                                                            " << endl;
                cout << "|       ||       || |_|   ||    ___|  |  _   | |_     _||   |                                                                                           " << endl;
                cout << "| ||_|| ||   _   ||       ||   |___   | |_|   |  |   |  |___|                                                                                           " << endl;
                cout << "|_|   |_||__| |__||______| |_______|  |_______|  |___|                                                                                                  " << endl;
                cout << endl << endl << endl; cout << endl << endl << endl;
                cout << " ______   ___   _______  __   __    ______   _______  __    _    _______  ___      _______  __   __  _______  __    _  ______   ______    __   __       " << endl;
                cout << "|      | |   | |       ||  | |  |  |      | |   _   ||  |  | |  |   _   ||   |    |       ||  |_|  ||   _   ||  |  | ||      | |    _ |  |  | |  |      " << endl;
                cout << "|  _    ||   | |       ||  | |  |  |  _    ||  |_|  ||   |_| |  |  |_|  ||   |    |    ___||       ||  |_|  ||   |_| ||  _    ||   | ||  |  | |  |      " << endl;
                cout << "| | |   ||   | |       ||  |_|  |  | | |   ||       ||       |  |       ||   |    |   |___ |       ||       ||       || | |   ||   |_||_ |  |_|  |      " << endl;
                cout << "| |_|   ||   | |      _||       |  | |_|   ||       ||  _    |  |       ||   |___ |    ___| |     | |       ||  _    || |_|   ||    __  ||       | ___  " << endl;
                cout << "|       ||   | |     |_ |       |  |       ||   _   || | |   |  |   _   ||       ||   |___ |   _   ||   _   || | |   ||       ||   |  | ||       ||_  | " << endl;
                cout << "|______| |___| |_______||_______|  |______| |__| |__||_|  |__|  |__| |__||_______||_______||__| |__||__| |__||_|  |__||______| |___|  |_||_______|  |_| " << endl;
                cout << endl << endl << endl; cout << endl << endl << endl;
                cout << " _______  ___      _______  _______  _______       _______       ___   __   __         _______       _______                                                     " << endl;
                cout << "|       ||   |    |   _   ||       ||   _   |     |   _   |     |   | |  |_|  |       |   _   |     |   _   |                                                    " << endl;
                cout << "|       ||   |    |  |_|  ||  _____||  |_|  |     |  |_|  |     |   | |       | ____  |  |_|  |     |  |_|  |                                                    " << endl;
                cout << "|       ||   |    |       || |_____ |       |     |       |     |   | |       ||____| |       |     |       |                                                    " << endl;
                cout << "|      _||   |___ |       ||_____  ||       |     |       |     |   |  |     |        |       |     |       |                                                    " << endl;
                cout << "|     |_ |       ||   _   | _____| ||   _   |     |   _   |     |   | |   _   |       |   _   |     |   _   |                                                    " << endl;
                cout << "|_______||_______||__| |__||_______||__| |__|     |__| |__|     |___| |__| |__|       |__| |__|     |__| |__|                                                    " << endl;
                int key2 = getch();
                if (key2 == 'c') {
                    system("cls");
                    for (i = 1; i <= 3; i++) {
                        for (mem = 1; mem <= 23; mem++) {
                            for (j = 1; j <= 5; j++)
                                outwithyou();
                            cout << endl;
                        }
                        cout << endl;
                    }
                    int gr = 0;
                    for (x = 1; x <= initial_credit; x *= 10) gr++;
                    x /= 10; gr--;
                    i = 0;
                    while (x > 0) {
                        a[++i] = initial_credit / x % 10;
                        x /= 10;
                        if (x == 0) a[++i] = initial_credit % 10;
                    }
                    for (i = 1; i <= 7; i++) {
                        cout << credit(i) << " ";
                        for (j = 1; j <= gr+1; j++) {
                            outwithyoutoo();
                        }
                        cout << endl;
                    }
                    gr = 0;
                    for (x = 1; x <= initial_bet; x *= 10) gr++;
                    x /= 10; gr--;
                    i = 0;
                    while (x > 0) {
                        a[++i] = initial_bet / x % 10;
                        x /= 10;
                        if (x == 0) a[++i] = initial_bet % 10;
                    }
                    for (i = 1; i <= 7; i++) {
                        cout << bet(i) << " ";
                        for (j = 1; j <= gr+1; j++) {
                            outwithyoutoo();
                        }
                        cout << endl;
                    }
                    gr = 0;
                    for (x = 1; x <= sum_earn2; x *= 10) gr++;
                    x /= 10; gr--;
                    i = 0;
                    if (x == 0) {
                        a2[1] = 0;
                        gr++;
                    }
                    while (x > 0) {
                        a2[++i] = sum_earn2 / x % 10;
                        x /= 10;
                        if (x == 0) a2[++i] = sum_earn2 % 10;
                    }
                    for (i = 1; i <= 7; i++) {
                        cout << last_win(i) << " ";
                        for (j = 1; j <= gr+1; j++) {
                            outwithyouthree();
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
    return 0;
}
