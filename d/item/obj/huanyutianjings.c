
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "ħԴ��ʯ" NOR, ( {"tian jings", "tians", "jings"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "�ռ��������ϣ����Դ�������쾧������ħ����Ԩ�������仯���ɣ�"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("tianji1", 50);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "ħԴ" NOR);
		set("can_make", "all");
		set("power_point", 2000);
	}
}

int query_autoload() { return 1; }