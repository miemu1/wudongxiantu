#include <ansi.h>
inherit F_SAVE;
inherit F_DBASE;
/*�����µص������ѡ��������*/
nosave mapping didian =([
	"city":"����",
	"xueshan":"ѩɽ",
	"guanwai":"����",
	"emei":"��ü",
	"taishan":"̩ɽ",
	"city3":"�ɶ�",
	"beijing":"����",
	"xiangyang":"����",
	"huashan":"��ɽ",
	"quanzhen":"ȫ��",
	"foshan":"��ɽ",
	"fuzhou":"����",
]);
nosave int quest_time=0;//0Ϊ����ʱ�� 60=һ���ӣ��Դ�����

public void quest(object obj)//��ȡ����
{
	int i,j;
	mixed *files;
	string file;
	object ob,obj1;
	object *inv;
	string *di,di1;
	
	if(time()/86400 == obj->query("dytime")/86400)
	{
	    obj->set("dynumber",0);	
		obj->set("dytime",time());
	}
	
	if(obj->query("dynumber")>=22)
	{
		tell_object(obj,"����������Ѵﵽ���ޣ�\n");
		obj->delete("daily");
		return;
	}
	if(obj->query("daily/id"))
	{
		tell_object(obj,"���Ѿ���ȡ���ճ�����Ŀ��:"+obj->query("daily/name")+"����"+obj->query("daily/city")+obj->query("daily/place")+"�����"ZJURL("cmds:cesy remove")ZJSIZE(10)"����"NOR"��\n");	
		return;
	}
	
	di=keys(didian);
	di1=di[random(sizeof(di))];
	
	files = list_dirs("/d/"+di1+"/");
	file = "/d/"+di1+"/"+files[random(sizeof(files))]+".c";	
	if (! (ob = find_object(file)))
	{
		if (file_size(file)>=0)
		ob = load_object(file);
	}
	if(ob)
	{
		if(ob->query("no_fight")==1)
		{
			quest(obj);	
			return;
		}
        inv = all_inventory(ob);
		if(sizeof(inv)<1)
		{
			quest(obj);	
			return;
		}
		obj1=inv[random(sizeof(sizeof(inv)))];
		if (obj1->is_player())  
		{
			quest(obj);	
			return;
		}
		if (! obj1->is_character() || obj1->is_corpse())  
		{
			quest(obj);	
			return;
		}
		obj->set("daily/id",obj1->query("id"));
		obj->set("daily/name",obj1->query("name"));
		obj->set("daily/city",didian[di1]);
		obj->set("daily/place",ob->query("short"));
		if(quest_time>0) obj->set("daily/time",time()+quest_time);
		tell_object(obj,"��ȥ��ɱ��"+obj1->query("name")+",������"+didian[di1]+"��"+ob->query("short")+"���\n");
	}else quest(obj);	
}


public void set_shanchu(object me)//ɾ������  ����DAILY_D->set_shanchu(object me);
{
	me->delete("daily");
	tell_object(me,"��������ճ�����\n");
}



public void set_rewards(object me)//��ȡ����
{
    if(me->query("dynumber")>=22)
	{
		tell_object(me,"����������Ѵﵽ���ޣ�\n");
		me->delete("daily");
		return;
	}
	
	if(me->query("daily/time")>0&&me->query("daily/time")<time())
	{
		tell_object(me,"�����Ѿ����ڣ�\n");
		me->delete("daily");
		return;		
	}
	//������Ӹ�me��������
	
	
	me->set("dytime",time());
	//"/clone/money/thousand-gold",
	//"/clone/vip2/yanzhi",
	me->add("combat_exp",100000);
		me->add("potential",1000000);
		me->add("yuanbao",100);
		if(me->query("zhanling/s8") < 100)
		{
		me->add("zhanling/a8",100);
		me->add("zhanling/s8",100);
		tell_object(me,"������˴˴����񣬻����100ս����Ϊ��\n");
		}
		tell_object(me,"������˴˴����񣬻������Ϊ10��Ǳ��100��,100����ʯ��\n");
       me->delete("daily");
	   return;
}
