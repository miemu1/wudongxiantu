// magic-beast.c

#include "/clone/npc/magic-beast.h"

void setup()
{
	set_name("[33m����[33m[2;37;0m", ({"mycmds_ofen"}));	
	set("gender", "����");		
	set("unit", "ֻ");
	set("long", "$YEL$����$YEL$[2;37;0m
����΢Ц��ħ���ޡ�
");
	set("owner", "weixiao_1");
	set("owner_name", "΢Ц");
	set_temp("owner", "weixiao_1");
	set_temp("owner_name", "΢Ц");
	last_age_set = 0;
	::setup();
}


