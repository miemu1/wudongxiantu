#include <ansi.h>
inherit ITEM; 

int generate_taoist;
void set_generate_taoist(int i) 
{
        generate_taoist = i;
}

int query_generate_taoist() 
{
        return generate_taoist;
}

void create()
{
        set_name("�ײ�", ({"coffin"}) );
        set_weight(3000);
        set("no_get", 1);
        set("unit", "��");
        set("long", "һ�ߺ���������ʯ�ף����滹��һ�����ι�״�����̣�Ҳ����ʲô�Źֻ��ء�");
        set("value", 2000);
        setup();
} 

void init() 
{
        add_action("do_push","push");
        add_action("do_turn","turn");
}

int do_push(string arg) 
{
        if( !arg || (arg!="coffin" &&  arg!="�ײ�") ) 
                return notify_fail("��Ҫ��ʲô��\n");
                
        tell_object(this_player(), "�ײ��ƺ�ֻ�в�ת(turn)���̲��ܿ������ش򿪡�\n");
        return 1;
}

int do_turn(string arg)
{
        object taoist;
        object me, mazeobj;
        int answer,puzzle;

        me = this_player();
        if( !arg )
                return notify_fail("��Ҫ������ת����һ�������ϣ�\n");
        if( me->query("neili") < 5000 )
                return notify_fail("����������������������̡�\n");      
        mazeobj = FUBEN_D->query_maze_mainobj(this_object());
        if( !(answer = (int)arg) || sizeof(mazeobj->query("quest/password")) < 9 )
                return notify_fail("��Ϲתʲô��\n");
        puzzle  = mazeobj->query("quest/password/1");
        puzzle += mazeobj->query("quest/password/2") * 10;
        puzzle += mazeobj->query("quest/password/3") * 100;
        puzzle += mazeobj->query("quest/password/4") * 1000;
        puzzle += mazeobj->query("quest/password/5") * 10000;
        puzzle += mazeobj->query("quest/password/6") * 100000;
        puzzle += mazeobj->query("quest/password/7") * 1000000;
        puzzle += mazeobj->query("quest/password/8") * 10000000;
        puzzle += mazeobj->query("quest/password/9") * 100000000;
        me->add("neili",-1500);
        message_vision("$N�����̲�����"+arg+"��λ��\n",me);
        if( ("X"+puzzle+"X") == ("X"+answer+"X") ) {
                if( query_generate_taoist() ) {
                        tell_room(this_object(), "һ�����֮�����֮��ײĴ��ˣ���������ʲô��û�С�\n");
                        return 1;
                }                 
                tell_room(this_object(), "һ�����֮�����֮��ʯ�׿�ʼ����������\n");
                message_vision(@LONG
��������һ��ͷ���������ڣ����ź�ɫ���۵Ŀ������ߣ����������̬����ƽ�ͣ�
��Ȼ�������ƺ�ֻ���ڳ�˯֮�С����ֺ�����ǰ������һ�����������������ͻ�����
ɫʯӡ��Ѥ����ҫ�����ִ�ϥ��������һ������������������ͭ��ˣ���ɫᦲ�����
�����ĸ�������Ȼ�Ǻ�ͼ�ư����׸Ǵ�֮��ʬ����յ�˫��ͻȻ������˫Ŀ֮��
���Ⱪ�䣬�漴�ӹ���һԾ�������������ڹ�������ǧ���Ե�ʣ������ֱ��ȽŶ���
ʮ����㣬�����������ֱ��ֱ�£��ֽŻ��������㹥����Ծ��ʯ��֮������Ƥ
�⼱��ή�����ݣ�ɲ��֮��㻯Ϊһ�߰׹����ã�
LONG, me);
                taoist = new("/maze/mausoleum/npc/king");
                taoist->move(environment(me));
                set_generate_taoist(1);
        } else
                message_vision("����ʲô��û�з�����\n",me);
        return 1;
}

