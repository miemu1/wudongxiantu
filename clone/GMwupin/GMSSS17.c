// god_eyes.c ħ������

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIG "ħ��" + HIM + "����" NOR, ({ "yan s3" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIC"һ����˸��"HIY"��Ŀ��â"HIC"��"HIG"��ʯ"HIC"����˵���ﲢ�������˼䣬���˾�η֮����Ȼ������"NOR"\n");
		set("base_value", 200);
		set("base_weight", 1);
		set("base_unit", "��");
	    set("tianji1", 40);
  		set("no_get",1);
		set("no_give",1);
  		set("no_drop",1);
  		set("no_sell",1);
  		set("no_steal",1);
		set("can_be_enchased", 1);
		set("magic/type", "all");
		set("magic/power", 400);
	}
	set_amount(1);
	setup();
}
