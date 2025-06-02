// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 
string look_stone(object me);

void create()
{
        set("short", "���ʯ");
        set("long", 
"�����ǻ�������߷壬ɽ��ƽ̨���ϵ�һ���ʯ(stone)����Ԩ\n"
"��������������ס���Ŀ��������ǧ�﷽Բ�����޼ʣ����ƾ�ɢ��\n"
"���ƻá���վ�����ﻳ�����ٷ�̤��ƮƮ���ɵĸо�������������"CYN"��"NOR"\n"
"���ȥ����ͷ��\n"
);
        set("outdoors", "chengdu");
        set("exits",([ /* sizeof() == 1 */
                "southdown" : __DIR__"suiroad3",
        ]));

                set("no_fight", 1); 
                set("no_magic", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);
        
        set("item_desc", ([
                "ʯ": (: look_stone :),
                "��ʯ": (: look_stone :),
                "stone": (: look_stone :),
        ]) );

        setup();
}

string look_stone(object me)
{
        return 
HIW + "   �������\n" + NOR + 
WHT + "  ��������ͣ�\n" +  NOR + 
HIW + "  ���ٰ˶Դǡ�\n" +  NOR + 
WHT + "  ҹ����������\n" +  NOR + 
HIW + "  �ߵ�����˼��\n\n" +  NOR + 
HIK + "         sui...\n" +  NOR;
}

void init()
{
        add_action("do_sui", ({"sui", "jump"}));
}


int do_sui()
{
        object me = this_player();
        
        if(me->is_busy()) return 1;
        me->start_busy(20);
        
/*semote goodbye
���� goodbye ֮��ϸ�������£�
��������������������������������������������������������������������������������
1.�޶����޸�������    ��΢�����ϸϸ����������Ϧ����ӳ��֮�£�������������˸ж���������ˮ�����ۿ�֮�У��ٳٲ������¡���
2.�޶����и�������    ��΢�����ϸϸ����������Ϧ����ӳ��֮�£�������������˸ж���������ˮ�����ۿ�֮�У��ٳٲ������¡���
3.����Ϊ�Լ��޸������֣���վ���������µı��ϣ���Ŀ��ȥ���������ƣ������ɾ���
�૵�������������������������Ҳ���������ˡ���˵�գ�����Ծ��������֮�С���
4.����Ϊ�Լ��и������֣���վ���������µı��ϣ���Ŀ��ȥ���������ƣ������ɾ���
�૵�����������Ҳ���������ˡ���˵�գ�����Ծ��������֮�С���
5.����Ϊĳ���޸������֣�������ĳ�˵���˵������Ҫ������..��������...��ǵ�����...��...��...�һ������....��Զ�ᣡ����
6.����Ϊĳ���и������֣�������ĳ�˵���˵������Ҫ������..��������...��������...��...��...�һ������....��Զ�ᣡ����
7.����ע��            ����ע��
8.ʹ�ô���            ��20 ��
��������������������������������������������������������������������������������*/
 
                set_temp("can_redlsuistone", 1, me);
                message_vision(YEL "$N��ͷ�������߽��µľ�ʯ��\n" NOR, me);
                call_out("do_sui2", 2, me); 
                return 1;
}

void do_sui2(object me)
{
                switch(query_temp("can_redlsuistone", me))
                {
                        case 1:
                                addn_temp("can_redlsuistone", 1, me);
                                me->command("goodbye " + query("couple/couple_id", me));
                                call_out("do_sui2", 3, me); 
                break;
                        case 2:
                                addn_temp("can_redlsuistone", 1, me);
                                me->command("goodbye " + query("id", me));
                                call_out("do_sui2", 4, me); 
                break;
                        case 3:
                                delete_temp("can_redlsuistone", me);
                                message_vision(YEL "$N��Ӱ��Խ��ԽԶ�����������������ԨƮȥ...\n" NOR, me);
                                call_out("do_sui3", 3, me); 
                break;
        }
}

void do_sui3(object me)
{
        me->move(__DIR__"inwind");
}


