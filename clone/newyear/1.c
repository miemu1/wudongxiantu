
#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void create()
{
	set_name(HIR "����~1" NOR, ({ "newyear card1" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�ž����ĺ�ɫ��Ƭ������д��һ����ɫ�Ĵ��֣�"HIY"��"NOR"�ݣ���˵����[2018�´�����]�����Ҳ���һ����Ŷ��\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "��");
		set("newyear_fu", "1");
	}
	set_amount(1);
	setup();
}
