
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int min, hrs, day, mon, age;
		string sec;
        string out_str;
    	sec = sprintf(" 														 "HIY"�� �ƺ��� ��     "NOR"  \n");
	sec += sprintf(WHT""WHT""WHT""NOR"\n");

    	sec += sprintf(HIY"	" + ZJURL("cmds:chjl quxiao")ZJSIZE(25)"ȡ��ǰ׺�ƺ�"NOR" ")+sprintf(WHT"						" + ZJURL("cmds:chjl quxiao1")ZJSIZE(25)"ȡ�³ɾͳƺ�"NOR" \n");
//    	sec += sprintf(HIY"  �� �ƺ� ��                    " + ZJURL("cmds:chjl quxiao1")ZJSIZE(25)"ȡ�³ɾͳƺ�"NOR" \n");
	sec += sprintf(WHT""WHT""WHT""NOR"\n");

if (me->query("chenghao/slr"))
        { 
        sec += sprintf(HIY"  ɨ��ɮ																"  + ZJURL("cmds:chjl slr")ZJSIZE(25)"����ƺ�"NOR" \n");
        sec += sprintf(HIW"  ��ͨ�ƺ�"NOR" \n");
    	}						
if (me->query("chenghao/zmjh"))
        { 
        sec += sprintf(HIY"  ������																"  + ZJURL("cmds:chjl zmjh")ZJSIZE(25)"����ƺ�"NOR" \n");
        sec += sprintf(HIW"  ��ͨ�ƺ�"NOR" \n");
    	}    	
	
		sec = replace_string(sec,"\n",ZJBR)+"\n";
		write(ZJOBLONG+sec+"\n");
		
		
		
        return 1;
}


