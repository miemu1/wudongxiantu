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
	set_name(HIR"���� �� �� �ԡ�"NOR, ({"zhengdao yueli book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 9500000);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "��");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","���� �� ֤ ����\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+name()+"��\n");

	me->set_skill("mingyue-blade", me->query_skill("mingyue-blade",1) + 180);//�������µ�
	me->set_skill("doomforce", me->query_skill("doomforce",1) + 180);//��ѩ��
	me->set_skill("wuyun-jianfa", me->query_skill("wuyun-jianfa",1) + 280);//�������ҽ�
	me->set_skill("xiyu-tiezheng", me->query_skill("xiyu-tiezheng",1) + 180);//����������
	me->set_skill("taohua-yuan", me->query_skill("taohua-yuan",1) + 180);//�һ�Թ
	me->set_skill("qingxin-pushan", me->query_skill("qingxin-pushan",1) + 180);//����������
	
	write(YEL"���꣬����С�ữΪһ�������������ƶ���"NOR"\n");
	
	add_amount(-1);
	return 1;
}