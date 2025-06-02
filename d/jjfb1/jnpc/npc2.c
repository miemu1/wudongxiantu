
inherit NPC;
#define JJ_SYS "/d/jjfb/jsys/jj_sys"
#define JJ_SYS1 "/d/jjfb1/jsys/jj_sys"
int ask_job();
int ask_job1();

void create()
{
   set_name("����",({ "jhuwei"}) );
   set("gender", "����" );
   set("age",18);

   set("long", "��Ի��ɫ���ǿգ��ռ���ɫ!����ż���һ�¡�\n");
                set("max_qi", 100000);
        set("eff_qi", 100000);
        set("qi", 100000);

        set("max_jing", 100000);
        set("jing", 100000);
        set("eff_jing", 100000);
        set("max_jingli", 100000); 
        set("jingli", 100000);  

        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 50000000000);
   set("combat_exp", 50000);
   set("dengji/s1",300);
   set("yiqi/s1",300);
  	set("inquiry", ([
        	"��ս�򵥿������" : (: ask_job :),
//        	"��ս���ѿ������" : (: ask_job1 :),

	]) );
   set("yiqi/s1",300);
   set("yiqi/s1",300);
   
   set_skill("blade",500000);
   set_skill("dodge",500000);
   set_skill("parry",500000);
   set_skill("force",500000);
   
        set("my_life", 999); // ����Ѫ����10%��ʱ����һ�Σ����øò���Ϊ0

   setup();
   

}

void new_life()
{
        object me = this_object();
        
        // ������Ѫ
        me->set("eff_qi",me->query("max_qi",  me), me);
        me->set("qi",me->query("max_qi",  me), me);
        me->set("eff_jing",me->query("max_jing",  me), me);
        me->set("jing",me->query("max_jing",  me), me);
        me->set("jingli",me->query("max_jingli",  me), me);

        me->clear_condition();

        me->interrupt_me(this_object());

        me->delete_temp("no_perform", me);
        me->delete_temp("no_exert", me);

        set_temp("apply/attack", 10000000);
        set_temp("apply/unarmed_damage", 400000); 
        set_temp("apply/damage", 200000); 
        set_temp("apply/armor", 100000);
        set_temp("apply/qy", 70);  // ����
        set_temp("apply/fy", 70);  // ��Ե              
        me->add("my_life", -1);

        message_vision(HIG "\n$N" HIR "�ճ��������˵����������͡�ԡ����������Ҫ����꣡�������ҵĸ��顢ԡѪ������\n\n" NOR, me);
        
        return; 
}
int receive_damage(string type, int damage, object who)
{
        object ob, landie;
        int tzlv;

        object me = this_object();

        if (! who)return 0;

        // ���������ڣ������κ��˺�
        landie=me->query("mylandie", me);
        if (objectp(landie))
        {
                message_vision(HIC "$N" HIC "�������ֽУ���$n" HIC "�Ĺ��ƺ�����ᡣ\n" NOR, me, who);
                return 0;
        }

        // ��װ��׷���˺�
        if (objectp(who))
        {
                tzlv = to_int(who->query_temp("modequip_itemmake_level", who));
                
                if (tzlv == 3)// 
                {
                        damage *= 2;
                        this_object()->start_busy(5+random(6));
                        tell_object(HIM "�������װ��׷���˺�������æ�ң�\n" NOR);
                }
                else if (tzlv == 4)
                {
                        damage *= 3;
                        start_busy(5+random(6));
                        tell_object(HIM "���컯��װ��׷���˺�������æ�ң�\n" NOR);
                        if (random(10) < 7)
                        {
                                set_temp("no_perform", 1);
                                call_out("remove_no_perform", 10);
                                tell_object(HIC "���컯��װ��׷�ӷ���10�룡\n" NOR);
                        }
                }
        }
        
        if( !me->query("my_life", me))return ::receive_damage(type,damage,who);

        if( me->query("qi", me)<me->query("max_qi", me)/10 )
        {
                new_life(); // ����һ��
                return 0;
        }

        return ::receive_damage(type, damage, who);
}
void check_life()
{
        object env;
        
        // ���life<=1������
        if (5)
        {
                message_vision(HIR "\n$N" HIR "����һ��������ɢ�����䡣\n" NOR, this_object());

                destruct(this_object());
        }
}

void unconcious()
{
    die();
}
void die()
{
	object me,ob,memory,env,obj,item,corpse;
	mapping team;
	string location;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = query_temp("last_damage_from");

        if (query("my_life"))
        {
                new_life();
                return;
        }
        env = environment(this_object());
		if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));

      if(me->query("huoyuediann")<80)
{
      me->add("huoyuediann",5);
}

}
int ask_job()
{
	object me,jjmem;

	me = this_player();




	if(me->query("kuangdao/menpiao") < 1)
	{
		tell_object(me, HIG"�Ǻǡ�,��ĸ����������㣬ǩ�����ã�\n"NOR);
        return 1;
    }
	if(JJ_SYS->query_room_amount() >= 2000)
	{
		tell_object(me,"�����Ѿ�����̫�࣬��ӭ�´β��롣\n");
		return 1;
	}
	//ɾ���ɵĸ���
	jjmem = me->query_temp("jroom/jjfb_jjmem");
	if(objectp(jjmem))
	{
		jjmem->delete("user_id");
	}
	//�����µĸ���
	me->add("kuangdao/menpiao",-1);
	me->apply_condition("jjfb",90);
	JJ_SYS->jjfb(me);

	return 1;
}
int ask_job1()
{
	object me,jjmem;

	me = this_player();





	if(me->query("kuangdao/menpiao") < 1)
	{
		tell_object(me, HIG"�Ǻǡ�,��ĸ����������㣬ǩ�����ã�\n"NOR);
        return 1;
    }

	if(JJ_SYS->query_room_amount() >= 2000)
	{
		tell_object(me,"�����Ѿ�����̫�࣬��ӭ�´β��롣\n");
		return 1;
	}
	//ɾ���ɵĸ���
	jjmem = me->query_temp("jroom/jjfb_jjmem");
	if(objectp(jjmem))
	{
		jjmem->delete("user_id");
	}
	//�����µĸ���
	me->add("kuangdao/menpiao",-1);
	me->apply_condition("jjfb",90);
	JJ_SYS1->jjfb(me);

	return 1;
}