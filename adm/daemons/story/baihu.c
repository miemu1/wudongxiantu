// story:baihu �׻�

#include <ansi.h>

int give_gift(string name);

nosave mixed *story = ({
        "��ͥ��",
        "̫�׽��ǣ�����̫�����˹���Ⱥ�ɸ��磬��֪����Ҫ��ʲô���á�",
        "ͯ�ӣ�ʦ����̫���Ͼ����ˡ�",
        "̫�׽��ǣ�Ŷ���������ã�",
        "̫���Ͼ������ǰ���ʱ��Ҳ����ˣ�����߰ɣ���Ȼ�ٵ���̫��������Ҫ�����ˡ�",
        "̫�׽�����¶��ɫ��������ʲô��",
        "̫�׽��ǣ�������ͯ������ȥǣ�ҵ���������",
        "ͯ�ӣ��ǣ�˵�շɱ����� ����",
        "̫���Ͼ���̫�׽��ǰ������Ǹ������ܵ�̫��������������ֻ�ɺף���óٵ���",
        "̫�׽��ǻ�Ȼ����������ǣ����ǣ�����������ɺ׿죡������ϲ�������Ҫ���ꡣ",
        "̫���Ͼ���̫�׽��ǳ��ɺ׷�ȥ ����",
        "ͯ�ӣ�ʦ���������ˡ��������������~~",
        "ͯ�ӣ�������ʦ�������ˣ��������ʱ���ȥ���档",
        "ͯ�ӣ�С����С�����ҳ�ȥ����ʹ�����𵽴�����Ŷ��",
        "С������~����~��",
        "ͯ�ӣ��ðɣ������ˣ�˵��ͯ�ӷɱ����� ����",
        "С���������˳�ȥ ����",       
        (: give_gift, "baihu" :),
        "��˵�׻�(white tiger)һ���Ҵڣ����˷��䡣",
});

string prompt() { return HIM "���񻰴�˵��" NOR; }

// ÿ��һ��
int interval() { return 24 * 60 * 60; }


void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift(string name)
{
        object ob;

        ob = new(CLASS_D("misc/") + name);
        if (! objectp(ob))
                return 0;

        NPC_D->place_npc(ob);
        if (! objectp(environment(ob)))
        {
                destruct(ob);
                return 0;
        }

        CHANNEL_D->do_channel(find_object(STORY_D), "sys",
                              ob->name() + "������" + environment(ob)->short() +
                              "(" + base_name(environment(ob)) + ")��");
        return 1;
}

