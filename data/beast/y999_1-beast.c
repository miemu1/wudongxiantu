// magic-beast.c

#include "/clone/npc/magic-beast.h"

void setup()
{
	set_name("[33m��ҹ[2;37;0m[2;37;0m", ({"mycmds_ofen"}));	
	set("gender", "����");		
	set("unit", "��");
	set("long", " $YEL$��ҹ$NOR$[2;37;0m
����ŷ�����ǵ�ħ���ޡ�
");
	set("owner", "y999_1");
	set("owner_name", "ŷ������");
	set_temp("owner", "y999_1");
	set_temp("owner_name", "ŷ������");
	last_age_set = 0;
	::setup();
}


