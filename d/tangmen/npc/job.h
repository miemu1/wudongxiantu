#include <ansi.h>;

int ask_job()
{
        object me;
        mapping myfam;
        
        me = this_player();
        myfam = (mapping)me->query("family");
        

        if (! myfam || myfam["family_name"] != "��������")
        {
                command("say �������ǵ�������˵�ҵ������㲻һ������������ȥ�ɣ�");
                return 1;
        }

        if (me->query("tangmen/yanli") >= 100)
        {       
                command("gongxi");
                command("say ���㳤��һ���˲ţ���֪������һ���ϣ���ɽȥ�ɣ�");
                me->set("tangmen/upshan", 1);
                return 1;
        }

        if (me->query_temp("started", 1))
        {
                command("say ��������Ϊʲô��ȥ����");
                return 1;
        }
        
        if (me->query_temp("tmjob_failed"))
        {
                me->delete_temp("tmjob_failed");
                me->apply_condition("tmagain", 10);
                command("hmm");
                command("������ȥЪЪ�ɣ�����������\n");
                return 1;
        }               
        
        if (me->query_condition("tmagain") > 0)
        {       command("heng");
                command("say ������˵һ�£���ȵȰɣ�");
                return 1;
        }        

        if (me->query_temp("jobok") == 1)
        {
                command("say �úã��ɵĺã�����ȥЪЪ�ɡ�");
                me->add("combat_exp", 3000);
                me->delete_temp("started");
                me->delete_temp("find_wz");
                me->apply_condition("tmjob", 0);
                me->delete_temp("jobok");
                me->add("tangmen/yanli", 1);
                return 1;
        }
        

        command("say ��ȥ����ץһֻ���ӻ����ɡ�");
        command("say ���²���������ϵ�����ǰ�̣�һ��Ҫȫ��ȥ����");
        command("say �Ҳ����Ļ������ʱ��ˣ�˵�������ջ�");

        me->set_temp("started", 1);
        remove_call_out("putting");
        call_out("putting", 2 , me);
                       
        return 1;
}

int putting(object me)
{
        object ob1,ob2;
        string wh1,wh2;
        string *str = ({"/d/tangmen/kedian","/d/tangmen/edajie",
                        "/d/tangmen/tjpuzi","/d/tangmen/hcfdian",
                        "/d/tangmen/tsqianz","/d/tangmen/xdajie",
                        "/d/tangmen/tmbingqi","/d/tangmen/ndajie",
                        "/d/tangmen/bdajie1","/d/tangmen/bdajie2",
                        "/d/tangmen/jiulou","/d/tangmen/zhongxin",
                       });
        wh1 = str[random(sizeof(str))];
        wh2 = str[random(sizeof(str))];
        ob1 =new("/d/tangmen/npc/askdizi1.c");
        ob2 =new("/d/tangmen/npc/askdizi2.c");
        ob2->set("dname", me->query("id"));
        ob1->set("dname", me->query("id"));
        ob1->apply_condition("tmjob1", 10);
        ob2->apply_condition("tmjob1", 15);
        me->apply_condition("tmjob", 20);
        ob1->move(wh1);
        ob2->move(wh2);        
        tell_object(me, HIC "Ҫ��ȥ��ذ���\n" NOR);
        return 1;
}       
        

