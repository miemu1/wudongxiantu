inherit NPC;

string ask_xiaoaoquan();

void create()
{
    set_name("���ݳ���", ({"zong shi"}));
    set("long", "һ����ĸߴ�˧���ޱȡ�ò���˰���΢΢һЦ���Ե���ǧ��Ů���Ĵ�˧�ȡ�\n");
    
    set("combat_exp", 10000000);
    set("gender", "����");
    set("age", 35);
    set("inquiry", ([
        "���ּ���" : (: ask_xiaoaoquan :),
        ]));
    
    setup();
}

void init()
{
    add_action("disable", ({"kill", "hit", "fuhuo", "touxi", "fight", "ansuan", "steal"}));
}

int disable(string arg)
{
    object who = this_player();
    
    if (arg != "zong shi")
        return 0;
    
    tell_object(who, "����ͼ��ս���ݳ���\nֻ�������������һȭ��������о��޴����㡣\n");
    tell_object(who, "ȭͷͣ������ǰ����ͷ�����亹����\n");
    return 1;
}

string ask_xiaoaoquan()
{
    object who = this_player();
    
    if (who->query_skill("spells", 1))
        return "����ϰ�����ּ��ܣ���������������ˡ�";
    else
    {
        who->set_skill("xiaoao-quan", 600);
		who->set_skill("youzhi-jian", 600);
		who->set_skill("spells", 600);
        return "�Ҵ��������ּ��ܣ��˷������ޱȣ�������ú�����";
    }
}