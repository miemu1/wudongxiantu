#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;
	
	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
	set_name(HIR"���������衿", ({"qljgss book"}));	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 1);
		set("unit", "��");
		set("base_weight", 1);
		set("base_value", 100);
		set("long"," ��̫��ר�����ƹ�����\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");
if(me->query_skill("qinglian-jiange") > 600)
			return notify_fail("��ȼ�̫�����Ѿ��޷������ˡ�\n");
		else {
	me->set_skill("qinglian-jiange", me->query_skill("qinglian-jiange",1) + 999);
	write(YEL"��ѧ�����������裡"NOR"\n");
	write(YEL"���֮����������һ���´ʾ�һ����"NOR"\n");
	
	add_amount(-1);
        return 1;}
}