// yanshang2.c ����ͷ��
//Yanqi 08/11/2k
//������160k������@yeju

#include <ansi.h>
inherit NPC;
int ask_job();
int ask_rbd();
int ask_lhfb();

void create()
{
        set_name(HIR"��սʹ"NOR, ({ "fu ben", "fu", "ben" }));
        set("gender", "Ů��");
        set("age", 12+random(20));
        set("long", "����boss��ս����ʹ��\n");
        set("combat_exp", 90000000);        
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 90000000);
        set_skill("dodge", 2000000);
        set_temp("apply/attack", 2000005);
        //set_temp("apply/defense", 200005);
        set("inquiry", ([
                "����������ս": (: ask_job :),
			    // "�տ��ֻ�": (: ask_rbd :),
				"�ֻظ���": (: ask_lhfb :),
                 
        ]));
        set("chat_chance", 3);
        set("chat_msg", ({
                "��սʹ����λӢ������սһ�����������أ�\n",
        }) );
        //carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
        setup();        
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int ask_job()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if( exp1 < 400000)
        {
                command("say ��ʵ��̫���޷���ս");
                return 1;
        }
/*        
        if (me->query_condition("job_busy")) 
        {
                command("say ����æ������������أ���һ����������Ҫ����ɣ���Ҳ��������cond����鿴�Լ�������״̬��");
                return 1;
        }
*/                       
command("whisper "+me->query("id")+" ��������ʮ��ǿ�����Ҫ���İ������������ȥ�޾���Ԩ��");
	me->move("/d/maze/jiutou/enter");
        return 1;
}

int ask_lhfb()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if( exp1 < 4000000000&&(me->query("id") != "dodge_1")&&(me->query("id") != "sword_1"))
        {
                command("say ��ʵ��̫���޷���ս");
                return 1;
        }
		
		if (!(me->query_skill("lunhui-sword", 1)))
                return notify_fail("�������ɾ���򲻹�������ʩչ" + name() + "��\n");
/*        
        if (me->query_condition("job_busy")) 
        {
                command("say ����æ������������أ���һ����������Ҫ����ɣ���Ҳ��������cond����鿴�Լ�������״̬��");
                return 1;
        }
*/                       
command("whisper "+me->query("id")+" �ֻظ�������Ī�⣬�仯�޳���·��С�ģ�");
write(HIB+"\n��ֻ������ǰһ����ͻȻʲôҲ��������ʲôҲ������......\n\n"+NOR,);
        write(HIB+"ֻ�������岻�ϵ���׹......\n\n"+NOR,);
       write( HIB+"׹���޾��ĺڰ�......\n\n"+NOR,);
        write(HIB+"��Ȼ�·�һֻ����������һ��......\n\n"+NOR,);
        write(HIB+"ڤڤ����Լ�������󶣶�������ײ��......\n\n"+NOR,);
        write(HIB+"������һ���������Լ���������һ���������ƺ�����İ��������......\n\n"+NOR,);
	
	me->move("/d/death/liudaolunhui/wujiandao");
        return 1;
}

int ask_rbd()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if( exp1 < 400000)
        {
                command("say ��ʵ��̫���޷���ս");
                return 1;
        }
/*        
        if (me->query_condition("job_busy")) 
        {
                command("say ����æ������������أ���һ����������Ҫ����ɣ���Ҳ��������cond����鿴�Լ�������״̬��");
                return 1;
        }
*/                       
command("whisper "+me->query("id")+"�����Ҫ���İ������������ȥ��");
	me->move("/d/maze/rbd/dadao1");
        return 1;
}
