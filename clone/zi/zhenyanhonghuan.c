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
	set_name(HIR"���� �� �� �ԡ�"NOR, ({"zhengdao honghuang book"}));
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
		set("long","����ġ�\n");
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

	me->set_skill("zhenwu-unarmed", me->query_skill("zhenwu-unarmed",1) + 180);//�������������ȭ
	me->set_skill("yinyang-strike", me->query_skill("yinyang-strike",1) + 180);//�������������޼�������
	me->set_skill("huanmo-longtianwu", me->query_skill("huanmo-longtianwu",1) + 280);//��ħ������
	me->set_skill("lunhui-finger", me->query_skill("lunhui-finger",1) + 180);//����ֻ�����ָ
	me->set_skill("wuji-cuff", me->query_skill("wuji-cuff",1) + 180);//�����޼�������ȭ
	me->set_skill("zhutian-bu", me->query_skill("zhutian-bu",1) + 180);//���컯��
	me->set_skill("jiutian-xiaoyaobu", me->query_skill("jiutian-xiaoyaobu",1) + 180);//������ң��
	write(YEL"��о������һ�����"NOR"\n");
	
	add_amount(-1);
	return 1;
}