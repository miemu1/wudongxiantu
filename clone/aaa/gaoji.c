
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"�߼�����"HIY"��"HIC"ʯ" NOR, ({"gao stone", "ling", "shi"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIY"�ͼ�������ʯ����֮һ�е�������������װ��ʯ��"NOR"\n");
		set("spectxt", "��������Ĳ��ϡ�\n");
		set("unit", "��");
		set("no_put", 1);
		set("value", 80000000);
		set("shenbing",10);
		set("yuanbao", 2555);
		set("item_origin", 1);
		set("material_attrib", "magic stone");
		set("material_name", HIY "�߼�����"MAG"��ʯ" NOR);
		set("can_make", "all");
		//set("not_make", ({ "ս��", "����", "����" }));
		set("power_point", 800);
	}
}

int query_autoload() { return 1; }