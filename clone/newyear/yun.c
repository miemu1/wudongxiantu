
#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void create()
{
	set_name(HIR "����~��" NOR, ({ "newyear cardg" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�ž����ĺ�ɫ��Ƭ������д��һ����ɫ�Ĵ��֣�"HIY"��"NOR"�ݣ���˵����[�����д���]��������ʦ�һ���������Ŷ��\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "��");
		set("newyear_fu", "��");
	}
	set_amount(1);
	setup();
}
