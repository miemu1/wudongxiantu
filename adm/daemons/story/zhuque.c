// story:zhuque ��ȸ

#include <ansi.h>

int give_gift(string name);

nosave mixed *story = ({
        "����ɽ����ɮʦͽ ����",
        "��ɮһ�����ݣ������ɽ�Ļ�Ϩ����ι���ȥ����",
        "ɳɮ����Ҫ�ż�ʦ��������Ѿ�ȥţħ�������Ž����ˡ�",
        "��˽䣺���˰ɣ�ʦ�������Ǿʹ�ɢ�˰ɣ��һ��ҵĸ���ׯ��ɳʦ�ܻ�������ɳ�ӣ�\n"
        "            ���ͻػ���ɽ������������ ������ ʦ����ɳʦ�ܣ�����˵��Σ�",
        "��ɮ��ʼ���濼��������⣡",
        "ɳɮ��ʼ���濼��������⣡",
        "���� ���� ����",
        "����գ�ʦ���������һ����ˣ��Ҵ�ţ����������˰Ž��ȣ�",
        "��ɮ�����ǣ�����赽�ˣ���գ�����~~��",
        "�����˫�ֻ����ŰŽ��ȣ�ɲ�Ǽ������𣬱�����к���� ����",
        "��ɮ�������µ�����С���������������������·�������",
        "���� ���� ����",
        "����ɽ�Ļ𽥽�Ϩ��",
        "���� ���� ����",
        "ɲ�Ǽ䣬��ֹ��ͣ���ض�ɽҡ������ɽ�д���������졣", 
        "ͻȻ��һֻ�޴�Ļ�����ķ�˰����ž��춯�ذ�Ľ����������ɽ����",
        "����գ����֣���",
        "��˽䣺�ѡ� ����",
        "ɳɮ�����ޣ���",
        "��ɮ���ܰ�~~~~~~~ ��",
        "���� ���� ����",
        "��ɮʦͽ����˲����ʧ����Ӱ���١�",        
        "......",
        (: give_gift, "zhuque" :),
        "��˵��ȸ(fire phoenix)��˯���о��ѣ��ӳ��˻���ɽ��",       
});

string prompt() { return HIM "���񻰴�˵��" NOR; }

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

