
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "��Դ��ʯ" NOR, ( {"tian jings4", "tians4", "jings4"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "�ռ��������ϣ����Դ��˾���ʥ�������������������仯���ɣ�"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("tianji1", 150);
        set("no_sell",1);
		set("max_buy",4);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "��Դ" NOR);
		set("can_make", "all");
		set("power_point", 3500);
	}
}

int query_autoload() { return 1; }