inherit NPC;

string ask_yeqiuquan();

void create()
{
    set_name("Ұ��ȭ��ʦ", ({"zong shi"}));
    set("long", "һ�����ֲ��µĴ󺺡�\n");
    
    set("combat_exp", 100000);
    set("gender", "����");
    set("age", 35);
    set("inquiry", ([
        "Ұ��ȭ" : (: ask_yeqiuquan :),
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
    
    tell_object(who, "����ͼ��սҰ��ȭ��ʦ\nֻ��Ұ��ȭ��ʦ�����������һȭ��������о��޴����㡣\n");
    tell_object(who, "ȭͷͣ������ǰ����ͷ�����亹����\n");
    return 1;
}

string ask_yeqiuquan()
{
    object who = this_player();
    
    if (who->query_skill("yeqiu-quan", 1))
        return "����ϰ��Ұ��ȭ����������������ˡ�";
    else
    {
        who->set_skill("yeqiu-quan", 3);
        return "�Ҵ�����Ұ��ȭ����ȭ�������ޱȣ�������ú�����";
    }
}