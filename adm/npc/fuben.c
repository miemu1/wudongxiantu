inherit NPC;
string do_fly() ;
void create()
{
	set_name(HIW"��ħ"NOR, ({ "xiaobai"}));
	set("gender", "Ů��");
	set("age", 20);
	set("per", 30);
	set("con", 30);
	set("int", 30);
	set("level", 20);
	set("icon","00964");
	set("dex", 30);
	set("str", 30);
	set("long",HIW"������ʦ��ħ�ķ����ƹܿռ䡣\n"NOR);
	set_skill("unarmed", 100);
	set_temp("apply/damage", 50);
	set("inquiry", ([
		"����": (:do_fly:),
	]) );
	set("combat_exp", 500000);
	set("attitude", "friendly");
	setup();
	carry_object("/d/city/npc/cloth/feature")->wear();
}

void init()
{
	add_action("fly","fly");
}


string do_fly()
{
	write(ZJOBLONG"���͸�����\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)+
	//	"ɱ�տ�:fly yz"ZJSEP
	//	"�ڿ�:fly lvliu"ZJSEP
	//	"����ռ�:fly qiyi"ZJSEP	
		"��ɽ�۽�:fly lunjian"ZJSEP
		"�����ؾ�:fly longzhu"ZJSEP
		"���˴���:fly turen"ZJSEP
		"�������:fly shilian\n");
		return "��ħ���ֻӳ�һ���ռ��ѷ죬һ�Ű������˽�ȥ��";
}
int fly(string arg)
{
	object me=this_player();
	write("�ٺ٣�С�ı���ˣ�����\n");
	if (arg=="shilian") me->move("/d/city/wuguan/qianting");
	else if (arg=="turen") me->move("/d/pk/enter");
	else if (arg=="longzhu") me->move("/fuben/longzhu/longzhu");
	else if (arg=="lunjian") me->move("/d/lunjian/enter");
	//else if (arg=="daojian") me->move("/maze/daojian/fightroom");	
///	else if (arg=="jiangshi") me->move("/maze/jiangshi/fightroom");
//	else if (arg=="shenlin") me->move("/maze/forestnew/enter");
//	else write(HIR"\n������û�������"NOR"\n");
	return 1;
}
