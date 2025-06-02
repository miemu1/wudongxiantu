// bigmonkey.c

inherit NPC;

void create()
{
    set_name("���Գ", ({ "big monkey", "yuan", "dabai yuan",}) );
    set("gender", "����");
    set("race", "Ұ��");
    set("age", 65);
    set("long",
	"����һֻ���Գ����ֵ��Ǵ��������ŵõ�һ�󸯳�֮����ԭ����Գ����ŧѪģ��������һ���󴯣�"+ZJURL("cmds:lifeheal dabai yuan")+ZJSIZE(22)+"����"NOR"����\n");
    set("combat_exp", 50000);
    set("shen_type", 1);
    set("attitude", "peaceful");
    set("limbs", ({ "Գ��", "ǰצ", "��צ", "β��" }) );
    set("verbs", ({ "bite", "claw" }) );

    set("water", 200);
    set("food", 200);

    set("apply/attack", 100);
    set("apply/defense", 100);

    set_skill("unarmed", 25);
    set_skill("parry", 20);
    set_skill("dodge", 20);
    set("bag_count",1);
    
    setup();
}
void init()
{
    add_action("do_lifeheal", "lifeheal");
}
int do_lifeheal(string arg)
{
    object weapon, bag, me = this_player();
    if (query("bag_count")<1 || me->query("family/family_name") !="����")
    {
	write("��Գһ��������������������ҽ�Σ�\n");
	return 1;
    }
    if (me->query("gongxian") < 12000)
    {
	write("��Գ������һ�ۣ�������������������ҽ�Σ�\n");
	return 1;
    }
    
    if( !arg || arg != "dabai yuan")
    {
	write("�����ʲôѽ?\n");
	return 1;
    }
    if (!present("fish bone", me))
    {
	write("���ᣬ�ܿ������ܷ��Ƥ����\n");
	return 1;
    }
    if (!objectp(weapon = me->query_temp("weapon")) ||
	((string)weapon->query("skill_type") != "sword" &&
	 (string)weapon->query("skill_type") != "blade"))
	 return notify_fail("��û�й������������������\n");
    if (random(100) > 80) {
        message_vision(
    "$N��ұ߼��϶˵ķ��ߣ���б���п���������ĸ�Ƥ��ֻ��������
    �����һ���Ͳ�������$N���Ͳ�������һ�ߣ���������룬������Ƥ
    �ϴ���һ����С�ף��ٽ���Ƥ˺��ϸ˿������С�״�ᣬ��ǿ����Գ
    �ĸ�����ã��ڴ��ڷ��ϲ�ҩ�����á�������Գ�Ѿ��������磬$N�������˿��������뻹�ǸϽ����һ������ֵİ����ɡ�\n", me);
         bag = new("/d/mingjiao/obj/bag");
         bag -> move (environment(me));
         bag ->set("book_count", 1);
         me->set("can_skill/jiuyang-shengong", 1);
    } else {
        message_vision(
    "$N��ұ߼��϶˵ķ��ߣ���б���п���������ĸ�Ƥ��ԭ���������ﳤ�˸�ŧ����
    $N��ŧ�������������룬������Ƥ
    �ϴ���һ����С�ף��ٽ���Ƥ˺��ϸ˿������С�״�ᣬ��ǿ����Գ
    �ĸ�����ã��ڴ��ڷ��ϲ�ҩ�����á�������Գ�Ѿ��������磬$N�������˿���������û$Nʲô���ˡ�\n", me);
    }
	add("bag_count",-1);
	return 1;
}
