// chuancai-jiyi.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "cooking"; }

int valid_learn(object me)
{
    return 1;
}

mapping query_menu(object me)
{
        return ([ "���ֻ���"   : ({ "xiangshu huasheng" }),
                  "������˺��" : ({ "mala ji" }),
                  "��˺��"     : ({ "shousi ji" }),
                  "���Ƽ�"     : ({ "sanhuang ji" }),
                  "��������"   : ({ "ganbian youyu" }),
                  "������˿"   : ({ "yuxiang rousi" }),
                  "��������"   : ({ "gongbao jiding" }),
                  "���Ͷ�Ƭ"   : ({ "hongyou dupian" }),
                  "���Ŷ���"   : ({ "mapo doufu" }),
                  "���޷�Ƭ"   : ({ "fuqi feipian" }),
                  "ëѪ��"     : ({ "maoxue wang" }),
                  "�㹽������"     : ({ "xianggujirong tang" }),
                  "ܽ�ص�����"     : ({ "furongdanhua geng" }),
                  "���������"     : ({ "qingheqiupan tang" }),
                  "��˿������"     : ({ "cuisibaiyu tang" }),
                  "������"     : ({ "fenzheng rou" }) ]);
}

int practice_skill(object me)
{
        object cailiao;

        if (! objectp(cailiao = present("cai liao", me)) ||
            cailiao->query_amount() < 1)
                return notify_fail("������û�в����ˡ�\n");

        if( query("qi", me)<50 )
                return notify_fail("������������ˣ��޷��������ա�\n");

        if( query("jing", me)<50 )
                return notify_fail("��ľ��񲻼ã��޷��������ա�\n");

        me->receive_damage("qi", 40);
        me->receive_jing("jing", 40);
        cailiao->add_amount(-1);

        return 1;
}
