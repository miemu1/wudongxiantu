// shidong10.c ʯ��

inherit ROOM;

#include <ansi.h>

string look_bi();
int do_sleep(string arg);

void create()
{
        set("short", "���֮��");
        set("long", @LONG
�ѷ�������Ե����ɣ��������嵤�������Ԫ��
LONG );
        set("item_desc",([
	        "ʯ��"  : (: look_bi :),
        ]));
	set("exits", ([
		"south" : __DIR__"shanmen",

	]));

        setup();
}
do_sleep(string arg);
void init()
{
        add_action("do_canwu", "canwu");
}

string look_bi()
{
       object me = this_player();
       string msg;

       if ((int)me->query("max_neili")<10000||me->query("combat_exp")<1000000||me->query("potential")<1000000)
       {
           msg = HIC "\n���ߵ����ܣ��о������������Ĵ�����\n"
                 "Ȼ���㹦�����㡣����ϸ������Щ����ȴһ������\n" NOR;
       }
       else
       {
           msg = HIW "���ߵ�ʯ��ǰ����ϸ�ۿ�ʯ���ϵ����ݣ�����ʯ�ڲ�������\n"
"�ڴ˴����Բ���ʯ�ڣ�������������˼ά���ԡ�ÿ�γɹ�������Ϊ-1000��Ǳ��-1000���������-1��\n"
"��������+1��\n"
                 WHT"("ZJURL("cmds:canwu �������� from bi")ZJSIZE(25)""HIY"ͻ�ƣ��������"NOR")\n"
                    "("ZJURL("cmds:canwu ���Կ��� from bi")ZJSIZE(25)""HIY"ͻ�ƣ���������"NOR")\n"
                    "("ZJURL("cmds:canwu ���ǿ��� from bi")ZJSIZE(25)""HIY"ͻ�ƣ��������"NOR")\n"
                    "("ZJURL("cmds:canwu ������ from bi")ZJSIZE(25)""HIY"ͻ�ƣ�������"NOR")" NOR;
       }

       return msg;
}

int do_canwu(string msg)
{
    object me = this_player();

    string where, witch;

    if (! msg)return notify_fail("ʲô��\n");

    if (sscanf(msg, "%s from %s", witch, where) != 2)
          return notify_fail("��ʲô��\n");

    if (me->is_busy())
          return notify_fail("��������æ���ء�\n");

    if (me->is_fighting())
          return notify_fail("����ս��Ŷ����С�ģ����ˣ�����\n");

    if(me->query("potential")<1000000)
          return notify_fail("���Ǳ�ܲ���1000���޷��ڴ����򣡣���\n");

    if(me->query("combat_exp")<1000000)
          return notify_fail("�����Ϊ����1000���޷��ڴ����򣡣���\n");


    if (witch != "��������"
     && witch != "������"
     && witch != "���ǿ���"
     && witch != "���Կ���")
          return notify_fail("���뿪��ʲô��\n");

    if (where != "bi")
          return notify_fail("����ûʲô����ͻ�Ƶİ���\n");

   /* if (me->query_skill("literate", 1)
        || me->query("learned_literate"))
          return notify_fail("�����ʯ�����˰���Ҳû����ʲô��\n");
*/
    if ((int)me->query_skill("force", 1) < 1200)
          return notify_fail("��Ļ����ڹ�����(1200)�����޷���ͨʯ���ϵĵ��ƣ�\n");

    if ((int)me->query("max_neili") < 10000)
          return notify_fail("���������Ϊ����(1��)���޷���ͨʯ���ϵĵ��ƣ�\n");

    if ((int)me->query("jing") < 200)
          return notify_fail("��ľ����޷����У��޷�����ʯ���ϵĵ��ƣ�\n");

    if (witch == "��������"
        && (int)me->query("bbkf") == 999)
          return notify_fail("��ı��������Ѿ�ȫ���������\n");

    else
    if (witch == "���Կ���"
        &&(int)me->query("nbkf") == 999)
          return notify_fail("������Է����Ѿ�ȫ���������\n");

     else
    if (witch == "���ǿ���"
        &&(int)me->query("glkf") == 999)
          return notify_fail("��ĸ��Ƿ����Ѿ�ȫ���������\n");

    else
    if (witch == "������"
        && (int)me->query("tbkf") == 999)
          return notify_fail("����������Ѿ�ȫ���������\n");

    me->receive_damage("jing", 95);

    me->start_busy(2);

    if (random(2) == 1 && witch == "��������")
    {
        me->add("str", 1);
         me->add("bbkf", 1);
           me->add("combat_exp", -1000000);
            me->add("max_neili", -10000);
            me->add("potential",-1000000);

        write(HIC "��ı۲�Ǳ�ܿ�����1%���������+1��\n" NOR);
        me->start_busy(2);
        return 1;
    }

    else
    if (random(2) == 1 && witch == "���Կ���")
    {
             me->add("int", 1);
         me->add("nbkf", 1);
           me->add("combat_exp", -1000000);
           me->add("potential",-1000000);
            me->add("max_neili", -10000);

        write(HIC "����Բ�Ǳ�ܿ�����1%����������+1��\n" NOR);

            return 1;
        }
        
    else
    if (random(2) == 1 && witch == "���ǿ���")
    {
                me->add("con", 1);
         me->add("glkf", 1);
           me->add("combat_exp", -1000000);
            me->add("max_neili", -10000);
	me->add("potential",-1000000);
        write(HIC "��Ĺ���Ǳ�ܿ�����1%���������+1��\n" NOR);
       return 1;
    }

    else
    if (random(2) == 1 && witch == "������")
    {
                me->add("dex", 1);
         me->add("tbkf", 1);
           me->add("combat_exp", -1000000);
           me->add("potential",-1000000);
            me->add("max_neili", -10000);

        write(HIC "��ı۲�Ǳ�ܿ�����1%��������+1��\n" NOR);
	me->start_busy(2);
            return 1;
        }

    else return notify_fail("����ͼ��ʯ�����о��йء�" + witch + "�������ݣ������������˵㣬û��ͻ�ƣ�\n");

}
int valid_leave(object me,string dir)
{
        if (dir == "out")
                tell_object(me,"���߳���ʯ�������صس����ڴ���֮�С�\n");

        return ::valid_leave(me,dir);
}

int do_sleep(string arg)
{
        object me=this_player();
        int lvl;

        lvl = (int)me->query("bbkf", 1) + (int)me->query("tbkf", 1) + (int)me->query("nbkf", 1) + (int)me->query("glkf", 1);
        if (lvl >= 400)
{
me->move("d/city/kedian");
}       
        return 1;
}