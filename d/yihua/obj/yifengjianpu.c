inherit ITEM;

void create()
{
	set_name( "�Ʒ罣��", ({ "jian pu", "pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");

		set("long", "����һ���Ʒ罣�ף����滭��һЩ����ֵֹ��ʻ���\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"yifeng-jian",	
//			"literate": 500,
			"exp_required":	100000,
			"jing_cost": 5,
			"difficulty":	10,
			"max_skill":	500,
		]) );
	}
}
