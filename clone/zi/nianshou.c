
#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void create()
{
	set_name(HIY "�����ٻ���" NOR, ({ "nianshou card" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�ž����Ľ�ɫ��Ƭ�����滭��һ�����޵�ͼ����\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "��");
	}
	set_amount(1);
	setup();
}
