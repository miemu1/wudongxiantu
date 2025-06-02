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
	set_name(HIY"�����������ܲ�"NOR, ({"foundation book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 1000);
        set("no_sell",1);
        set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","����һ��"HIG"������"NOR);
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
		
	me->set_skill("force", me->query_skill("force",1) + 50);//�����ڹ�
	me->set_skill("dodge", me->query_skill("dodge",1) + 50);//�����Ṧ
	me->set_skill("parry", me->query_skill("parry",1) + 50);//�����м�
	me->set_skill("unarmed", me->query_skill("unarmed",1) + 50);//����ȭ��
	me->set_skill("cuff", me->query_skill("cuff",1) + 50);//����ȭ��
	me->set_skill("strike", me->query_skill("strike",1) + 50);//�����Ʒ�
	me->set_skill("finger", me->query_skill("finger",1) + 50);//����ָ��
	me->set_skill("hand", me->query_skill("hand",1) + 50);//�����ַ�
	me->set_skill("claw", me->query_skill("claw",1) + 50);//����צ��
	me->set_skill("sword", me->query_skill("sword",1) + 50);//��������
	me->set_skill("blade", me->query_skill("blade",1) + 50);//��������
	me->set_skill("staff", me->query_skill("staff",1) + 50);//�����ɷ�
	me->set_skill("hammer", me->query_skill("hammer",1) + 50);//��������
	me->set_skill("club", me->query_skill("club",1) + 50);//��������
	me->set_skill("whip", me->query_skill("whip",1) + 50);//�����޷�
	me->set_skill("dagger", me->query_skill("dagger",1) + 50);//�����̱�
	me->set_skill("throwing", me->query_skill("throwing",1) + 50);//��������
	
	
	
	
	write(YEL"�����ⱾС���ӣ�ͻȻ��Ȼ������ǰ�����˵���ѧ�����Ժ�������������"NOR"\n");
	
	add_amount(-1);
	return 1;
}