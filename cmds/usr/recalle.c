#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file,shimen;
	string str;
	object ob;
 
	if (! environment(me)) 
		return 0; 

	if (! arg )
		return help(me);
			     if (me->is_fighting())
			return notify_fail("��������ȦȦ��ʱ�򣬱�����һ�����˳�����\n");
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_ghost()) 
		return notify_fail("���㻹������˵�ɡ�\n"); 
		
	if (me->is_in_prison())   
		return notify_fail("�����������ء�\n");

	if (! me->query("born"))
		return notify_fail("�㻹û�г����أ�\n");

	if (me->query("doing"))
		return notify_fail("�㻹���ʲô����\n");
		
	if (environment(me)->query("no_magic"))
		return notify_fail("�㷢�������е�Ź֣�\n");		
	
	if (arg == "back")
	{			
		if (me->query_temp("jun_quest/party"))
			return notify_fail("�㻹����ս����ʹ�ã���\n");

		if (present("biao huo", me))
			return notify_fail("�����ϴ�������������ʩչ��\n");
		
		if (present("letter", me) || present("receipt", me)) 
			return notify_fail("�����ϴ����ܺ�������ʩչ��\n");
		
		if(me->query("family/family_name") == "ħ��")
			shimen = "/d/wansong/fuguitin";
		if(me->query("family/family_name") == "��ڤ��")
			shimen = "/d/xuanminggu/xuanmingfeng";
		if(me->query("family/family_name") == "������")
			shimen = "/d/shenlong/dating";
		if(me->query("family/family_name") == "������")
			shimen = "/d/xingxiu/riyuedong";
		if(me->query("family/family_name") == "������")
			shimen = "/d/shaolin/fzlou2";
		if(me->query("family/family_name") == "�䵱��")
			shimen = "/d/wudang/xiaoyuan";
		if(me->query("family/family_name") == "������")
			shimen = "/d/emei/hcahoudian";
		if(me->query("family/family_name") == "ؤ��")
			shimen = "/d/city/gbxiaowu";
		if(me->query("family/family_name") == "�һ���")
			shimen = "/d/taohua/dating";
		if(me->query("family/family_name") == "��Ĺ��")
			shimen = "/d/gumu/zhengting";
		if(me->query("family/family_name") == "Ѫ����")
			shimen = "/d/xuedao/shandong3";
		if(me->query("family/family_name") == "ѩɽ��")
			shimen = "/d/xueshan/neidian";
		if(me->query("family/family_name") == "ŷ������")
			shimen = "/d/baituo/dating";
		if(me->query("family/family_name") == "���չ�")
			shimen = "/d/lingjiu/dating";
		if(me->query("family/family_name") == "�������")
			shimen = "/d/guanwai/xiaowu";
		if(me->query("family/family_name") == "Ľ������")
			shimen = "/d/yanziwu/shangyu";
		if(me->query("family/family_name") == "���ϻ���")
			shimen = "/d/dali/neitang";
		if(me->query("family/family_name") == "��ң��")
			shimen = "/d/xiaoyao/qingcaop";
		if(me->query("family/family_name") == "ȫ���")
			shimen = "/d/quanzhen/shiweishi";
		if(me->query("family/family_name") == "����")
			shimen = "/d/mingjiao/dadian";
		if(me->query("family/family_name") == "��ɽ��")
			shimen = "/d/huashan/qunxianguan";
		if(me->query("family/family_name") == "�������")
			shimen = "/d/heimuya/up1";
		if(me->query("family/family_name") == "��ɽ����")
			shimen = "/d/huashan/xiaowu";
		if(me->query("family/family_name") == "�ƻ���")
			shimen = "/d/yihua/yaoyue";
		if(me->query("family/family_name") == "��������")
			shimen = "/d/tangmen/tangltt";
		if(me->query("family/family_name") == "���Ƴ�")
			shimen = "/d/baiyun/zhongzhou";
		if(me->query("family/family_name") == "��ɽ��")
			shimen = "/d/shushan/shangqing";
        if(me->query("family/family_name") == "��ڤ��")
			shimen = "/d/xuanminggu/xuanmingfeng";
		if(me->query("family/family_name") == "佻�����")
			shimen = "/d/huanhua/zhenmei";
		if(me->query("family/family_name") == "�����")
			shimen = "/d/jueqing/zizhuxuan";
		
		if (base_name(environment(me)) == shimen)
			return notify_fail("���Ѿ����ˡ�\n");
		
			
		if(!me->query("family/family_name"))
			return notify_fail("����ʦ���𣿣�\n");

		message("vision", me->name() + "������������ǰ���ٻ���һ��Բ������������ǰ��"
			"�ռ䣬ֻ��Բ�ڵĿռ���ս�" + me->name() + "�����˽�ȥ��\n",
			environment(me), ({me}));
		
		tell_object(me, "��ӿռ��ѷ��������\n");

		me->move(shimen);


		return 1;
	}

     str = me->query_temp("pet_id");      
		     
     if (! stringp(file = me->query("can_whistle/" + str)))
		return notify_fail("�㲢û�����ħ���ޡ�\n");

	if (file_size(file + ".c") < 0)
		return notify_fail("�㲢û�����ħ����!\n");
				
	if (arg == "change" && ! me->query("beastdied"))
	{
		if (! objectp(ob = present(str, environment(me))))
			return notify_fail("������Ȱ����ħ�����ٻ�����������\n");
		
		if (ob->query("owner") != me->query("id"))
			return notify_fail("���ħ���޲�����������ԡ�\n");
				
		if (! living(ob)) return notify_fail("���ħ����Ŀǰ���ڻ���״̬�ء�\n");

		message_vision("$N������������ǰ���ٻ���һ��Բ����"
			"һ������$n����������\n", me, ob);
		
		if (! ob->receive_change(me))
		{
			message_vision("Ȼ��ʲôҲû�з��� :)\n", me);			
			return 1;
		} 
	} else
	if (arg == "recover" && ! me->query("beastdied"))
	{
		 if (! objectp(ob = present(str, me)))
			return notify_fail("�����ϲ�û���κ�������ħ���ޡ�\n");
				       
		if (ob != me->query_temp("is_changing"))
			return notify_fail("�����ϲ�û���κ�������ħ���ޡ�\n");  

		if (ob->query("owner") != me->query("id"))
			return notify_fail("�����ϲ�û���κ�������ħ���ޡ�\n");
					
		if (! living(ob)) return notify_fail("���ħ����Ŀǰ���ڻ���״̬�ء�\n");

		message_vision("$N�������ǣ������������ĺ�������$n�������������\n", me, ob);
		
		if (! ob->receive_recover(me))
		{
			message_vision("Ȼ��ʲôҲû�з��� :)\n", me);			
			return 1;
		}		  
	}

	else return help(me);
	return 1;
}

int help(object me)
{
 write(@HELP
ָ���ʽ : recall change|recover <id>
��ħ��������������������ħ���޸����ָ��Ϊ< recall reborn >
�ص����ݿ͵��ָ��Ϊ < recall back >��
HELP
    );
    return 1;
}