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
	set_name(HIY"����ͨ��"NOR, ({"gushen tombo"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1",1000);
        set("no_sell",1);
        set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("unit", "ö");
		set("base_unit", "ö");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","����������������أ�������ϧ�գ�\n");
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
		
		if ((me->query_skill("martial-cognize")-me->query_skill("martial-cognize"))>800)
                return notify_fail("��ѧ����̫���ˣ�������Ѿ�û����"+ name() +"��\n");
      else {
	me->set_skill("literate", me->query_skill("literate",1) + 150);//����ʶ��
	me->set_skill("xinfa", me->query_skill("xinfa",1) + 150);//�����ķ�"
	me->set_skill("magic", me->query_skill("magic") + 150);//:"��������"
	me->set_skill("medical", me->query_skill("medical",1) + 50);//����ҽ��
	me->set_skill("poison", me->query_skill("poison",1) + 50);//��������
	me->set_skill("sanscrit", me->query_skill("sanscrit",1) + 50);//����
	me->set_skill("buddhism", me->query_skill("buddhism",1) + 50);//�����ķ�
	me->set_skill("lamaism", me->query_skill("lamaism",1) + 50);//�����ķ�
	me->set_skill("taoism", me->query_skill("taoism",1) + 50);//�����ķ�
	me->set_skill("mahayana", me->query_skill("mahayana",1) + 50);//������͹�
	me->set_skill("count", me->query_skill("count",1) + 50);//��������
	me->set_skill("certosina", me->query_skill("certosina",1) + 50);//��Ƕ����
	me->set_skill("drawing", me->query_skill("drawing",1) + 50);//�滭����
	
	
	
	me->set_skill("tanqin-jifa", me->query_skill("tanqin-jifa",1) + 50);//���ټ���
	me->set_skill("chuixiao-jifa", me->query_skill("chuixiao-jifa",1) + 50);//���＼��
	me->set_skill("guzheng-jifa", me->query_skill("guzheng-jifa",1) + 50);//���ݼ���
	
	me->set_skill("martial-cognize", me->query_skill("martial-cognize",1) + 50);//��ѧ����
	me->set_skill("sword-cognize", me->query_skill("sword-cognize",1) + 50);//��������
	me->set_skill("craft-cognize", me->query_skill("craft-cognize",1) + 50);//��������
	  }
	if ((me->query("combat_exp")-me->query("combat_exp"))>500000000)
                return notify_fail("���exp����5E������Ѿ�û����"+ name() +"��\n");
      else {
		me->add("combat_exp",5000000);//��Ϊ
		me->add("magic_points",5000000);//���
	  }
	
	write(YEL"��ʹ����һö��Ǯ����Ǯ����һ�����ֱ���Ժ���Խ��������"NOR"\n");
	
	add_amount(-1);
	return 1;
}