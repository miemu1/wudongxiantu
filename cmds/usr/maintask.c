#include <ansi.h>
inherit F_CLEAN_UP;
mapping teshe=([
"��ɽ��":"��ɽ�ɷ�Ϊ���ںͽ��ڣ����Ի������ذ�ʦѧϰ���ܣ���ɽ���ڵ���ʹ����Ӧ�Ľ����н����˺��ӳɰ�ʦҪ����",
"�䵱��":"��ѧ�ķ����Ծ�����ߣ�250��ѧ���Կ�ʼ���ޡ��䵱���ж�����Ѫ�ӳɡ����޵ص㣺�䵱�ؾ�������Ǳ�ܡ�\n��ʦҪ��:������Ҫ��ϸ�",
"������":"�����ɵ����������޶�500������ר�ü��ܾ��ޣ�jingxiu�����������ڣ�������������ء���ʦҪ������",
"��ü��":"������ǰ�������࣬��Ѫ�ࡣ��ѧ��Ҫ����������������ɵ����������޶�500����ü����ר�ü��ܾ�����ָ��jingzuo��������΢����Ϊ��Ǳ�ܣ�����˵ȼ���أ���40��˵ȼ����Ծ���������ü��������Ů��ֻ�е���Ů�Կ��Գ��ҡ������Һ���ѧ�ټú͸�����У�δ������ѧ���м��ܵ�û���ڹ��;��С�",
"�һ���":"�һ�������������������������ѧ�ģ��������������м������Ṧ���˵������ʡ�",
"ؤ��":"ؤ����ӿ���ֱ��ѧ����ʮ���ƣ��������ɵ��ӣ��кſ��Խ��֮��������ʳ���ѧϰ��Ů��ֻ�ܿ����������Ľ����ؼ���",
"������":"���޼������Ϻ����������󹥻���������������50��������80�������������ƶ���",
"��ң��":"�������ʺ����˵����ɣ���ڤ�ڹ�ϵ���ߣ������ߣ�ʦ��������ǰ���˺�Ҳ�㡣",
"��Ĺ��":"��Ĺ��ŭ�������ڹ�ս�����ӳɿ����˺���",
"ȫ���":"���칦�ؼ�������Ԫ��������ս����ʹ�ã����������ظ���Ѫ�����ޡ���ѧ�ķ��������䵱�ؾ�������ߣ�250��ѧ���Կ�ʼ���ޡ�",
"������":"�������ƵĶ��Ե����ٶȺܿ졣",
"ѩɽ��":"ѩɽ�ɵ����������޶�500����ʦҪ������",
"Ѫ����":"Ѫ��ħ���ؼ�������Ѫ�󷨣������˺��ͼ����ȼ���Ѫ���ŵ����������޶�500����ʦҪ������",
"���չ�":"�˻�����Ψ�Ҷ���ս���ӳ��˺���",
"ŷ������":"ŷ���Ҹ�󡹦�ľ�����ת�������ӿ����ƶ�������",
"�������":"���������������ӿ����ƶ�Ч����",
"Ľ������":"Ľ�ݼ��ڹ������ϵ���ͣ���û�л��塣Ľ�ݼҶ�ת�������ǲ���������мܡ�",
"���ϻ���":"�μ��ڹ�һ�㣬����ʹ������������Ч�ӳɣ�100%������Ч��",	
"����":"��ʦ���������׺����ϰ�������񹦡��������޼ɸ���һ��������ʦ",		
"ħ��":"�޾����������ɣ�����ϰħ���������Բ�µ������",	
"�ƻ���":"ֻ��Ů�ӵ��������ţ����Ӹ�ɱ����",	
"����":"�������ţ��ó������붾��",			
]);

mapping task_describe=([
"һ":"����䶯��;�������ǽ����ˡ�Ҫ���ڽ������㣬�͵���ȷ����ĳ�������ɣ��������򲻿ɲ��ʣ������֮�޼�����ѡ��һ�����ɰ�ʦ��",
"��":"�����뽭������ѧ��һ�а�ʽ������̽������ġ�������ʦ����̣���ѧϰһ����ѧ��",
"��":"���뽭����ʱ������һ��Ǯ��������Ϊ����ʱ�����ͨ��һЩ�򵥵Ĺ�����׬ȡһЩǮ�������Ϊֵ��Ǳ�ܡ����������ѡ�������¹�����1���Ӻ�ϵͳ�Զ������㽱�������Ͱɣ����͡�",
"��":"���˵ĵط����н���������������е���������ʽ���������������ɣ������һ��ʦ������",
]);
//�������б�
mapping task_reward=([
"һ":(["combat_exp":30000,"potential":50000,"obj":"/clone/maintask/obj/yueka"]),
"��":(["combat_exp":10000,"potential":50000,"obj":"/clone/maintask/obj/tianxiang"]),
"��":(["potential":10000,"obj":"/clone/maintask/obj/jiuzhuan"]),
"��":(["combat_exp":30000,"potential":100000,"obj":"/clone/maintask/obj/bianxingdan"]),
]);

mapping work_place=([
"����":"walk ����",
"��ҩ":"walk ƽһָ",
"����":"walk ����",
"����":"walk ����",
]);
//�����书�ͷ��еص㡣
mapping menpai=([
"��ɽ��":(["walk":"walk �͵�ŵ","skill":"���¾Ž�"]),
"�䵱��":(["walk":"walk �������","skill":"̫��ȭ��̫����"]),
"������":(["walk":"walk ����","skill":"�׽�񹦣�������ʮ������"]),
"��ü��":(["walk":"walk ����ʦ̫","skill":"�ټ�ʮ��ׯ"]),
"�һ���":(["walk":"walk ��ҩʦ","skill":"���｣������ָ��"]),
"ؤ��":(["walk":"walk ��ȫ","skill":"����ʮ����"]),
"������":(["walk":"walk ժ����","skill":"������"]),
"��ң��":(["walk":"walk �밢��","skill":"��ڤ�񹦣��貨΢��"]),
"��Ĺ��":(["walk":"walk С��Ů","skill":"��������"]),
"ȫ���":(["walk":"walk ��־ƽ","skill":"���칦"]),
"������":(["walk":"walk �鰲ͨ","skill":"��������"]),
"ѩɽ��":(["walk":"walk ���ײ�","skill":"���������"]),
"Ѫ����":(["walk":"walk ����","skill":"Ѫ������"]),
"���չ�":(["walk":"walk ÷��","skill":"�˻�����Ψ�Ҷ���"]),
"ŷ������":(["walk":"walk ŷ����","skill":"��󡹦"]),
"Ľ������":(["walk":"walk Ľ�ݲ�","skill":"��ת���ƣ�����ָ"]),
"�������":(["walk":"walk ���","skill":"���ҵ�������ʤ����"]),
"���ϻ���":(["walk":"walk ������","skill":"������"]),
"����":(["walk":"walk �⹭Ӱ","skill":"�����񹦣���������"]),
"ħ��":(["walk":"walk ������","skill":"Բ���䵶��ħ����ϼ�"]),
"�ƻ���":(["walk":"walk �ƻ�����ū","skill":"���񹦣��ƻ���"]),
"����":(["walk":"walk ����","skill":"���������ٽ�"]),
]);
//������ɵĲ���
mapping task_requirement = ([
"һ":"family/master_name",//�ɹ���ʦ����ʦ��
"��":"study_skill",//��һ��ѧϰ����
"��":"task_work",//��ɹ���
"��":"shimen/lun",//��ʦ�ż�¼
]);
string task_msg(int task_process,string arg,object me);
int task_zt(object me);
int main(object me, string arg)
{
	int task_process = me->query("maintask");
	string guocheng;
	guocheng = chinese_number(task_process+1);
 if (task_process < sizeof(keys(task_reward)))//���ҶԱȣ��������
 {
  if (!arg)
   tell_object(me,task_msg(task_process+1,"task",me));   
   else
   tell_object(me,task_msg(task_process+1,arg,me));   
 }
 else
 tell_object(me,"���Ѿ���һ�������Ľ�����ʿ�ˣ�����������е�����������������Ľ�����\n");   
	return 1;
}
string task_msg(int task_process,string arg,object me)
{
string msg;
 if (task_process==1||task_process==3)
 {
 //�Ƿ�������
 if(arg!="task")
 {
 msg = ZJOBLONG+teshe[arg]+ZJBR"��ɫ�书��"+menpai[arg]["skill"]+"\n";
msg +=ZJOBACTS2+ZJMENUF(3,3,10,35); 
msg+="ѡ���ʦ:"+menpai[arg]["walk"]+ZJSEP;
msg+="���ؽ���:maintask\n";
return msg;
}
 msg = ZJOBLONG+task_describe[chinese_number(task_process)]+"\n";
  msg +=ZJOBACTS2+ZJMENUF(3,3,10,35); 
  if (task_process==1)
  {
  string *all_menpai_name,menpai_name;
  all_menpai_name=keys(menpai);
  foreach (menpai_name in all_menpai_name)  
  msg+=menpai_name+":maintask "+menpai_name+ZJSEP;  
  }
  else if(task_process==3)
  {
  string *all_work_name,work_name;
  all_work_name=keys(work_place);
  foreach (work_name in all_work_name)
  msg += work_name+":"+work_place[work_name]+ZJSEP;
  //1���Ӻ��Զ�������
  me->set("task_work",1);
  call_out("task_zt",60,me);
  }
  
 }
 else 
 {
 msg = ZJOBLONG+task_describe[chinese_number(task_process)]+"\n";
  msg +=ZJOBACTS2+ZJMENUF(2,2,10,35); 
  msg+="���ٸ���:walk "+me->query("family/master_name")+ZJSEP;
  }
  msg+="���ؽ���:maintask\n";
   return msg;
}
int task_zt(object me)
{
 string guocheng;
	guocheng = chinese_number(me->query("maintask")+1);
  if(me->query(task_requirement[guocheng]))//�����Ƿ����
   {
   	object ob;
   int bexp = task_reward[guocheng]["combat_exp"];
   int bpot = task_reward[guocheng]["potential"];
   me->add("combat_exp",bexp);
   me->add("potential",bpot);
  ob = new(task_reward[guocheng]["obj"]);
  ob->move(me);
  tell_object(me,"��ϲ�������������"+guocheng+"�������Ϊ��"+bexp+"��Ǳ�ܣ�"+bpot+"��"+ob->query("name")+"\n");
  me->add("maintask",1);
   }
   return 1;
}
int help(object me)
{
	write(@HELP
��������
HELP
	);
	return 1;
}
