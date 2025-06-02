// /cmds/usr/checkhouse.c �鿴�Խ���լ���ָ��
// By Alf, Last Update 2003.0720

#include <ansi.h>
#include <getconfig.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i, value;
    object ob;
    string type, msg, pass, *key;
    mapping house, build;

    seteuid(getuid());

    if(!arg)
        ob = me;
    else
        ob = LOGIN_D->find_body(arg);

    if(ob && ob != me && !wizardp(me))
        return notify_fail("ֻ����ʦ���Բ鿴���˵���լ�����\n");
    if(!ob)
        return notify_fail("����鿴����Ŀǰ�����ߡ�\n");

    build = ob->query("house/build");
    if(sizeof(build) == 0)
        return notify_fail((ob == me ? "��" : ob->name()) + "Ŀǰ��δ�ڡ�"
                            HIY + LOCAL_MUD_NAME() + NOR"��ӵ���κ���լ��\n");
    msg  = HIC "\n" + (ob == me ? "��" : ob->name()) + "Ŀǰ�ڡ�"
           HIY + LOCAL_MUD_NAME() + HIC"��ӵ�е���լ�У�\n";
    msg += HIG "-----------------------------------------------------------------\n" NOR;
    key = sort_array(keys(build), 1);
    for(i = 0; i < sizeof(key); i++)
    {
        house = ob->query("house/" + key[i]);
        if(key[i] == "user")    type = "���סլ";
        if(key[i] == "bang")    type = "���פ��";
        if(key[i] == "xian")    type = "ɢ�ɾ���";
        msg += sprintf(HIW "һ��λ��" HIC "%s%s" HIW "��%s��"
                       HIG "%s" HIW "������ֵ" NOR, house["base"]["place"],
                                                    house["base"]["name"],
                                                    type,
                                                    house["name"]);
        if(key[i] == "xian")
            msg += HIW "�ѷǷ�����Լ��㡣\n" NOR;
        else
            msg += sprintf(HIY " %-6d���ƽ�" HIW "��\n", house["value"]);

        if(wizardp(me) && wiz_level(me) > 3)
            msg += sprintf(HIW "%s��" HIC "%s%s" HIW "������"
                           HIG "%s" HIW "����լ����Ϊ����"
                           HIY "%s" HIW "����\n" NOR, (ob == me ? "��" : ob->name()),
                                                      house["base"]["place"],
                                                      house["base"]["name"],
                                                      house["name"],
                                                      house["pass"]);
    }
    msg += HIG "-----------------------------------------------------------------\n" NOR;
    tell_object(me, msg);
    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ��checkhouse [ID]

���ָ��������鿴�Լ�ӵ�е���լ�����
��ʦ���ø�ָ��鿴ĳһ��ҵ���լ�����

HELP);
    return 1;
}