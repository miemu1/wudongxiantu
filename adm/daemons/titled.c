// �ƺ�demo by ����ҹ��(baiyi666/lude)
#pragma optimize
#pragma save_binary

#include <ansi.h>
//�ɼӳɻ�������ֵ
mapping titles = ([
"���Ͻ���":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_poison":5,"obtain":"���Ͻ����ﵽ600����"]),
"��������":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_magic":5,"obtain":"�����ɾ��ﵽ600����"]),
"������":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_metal":5,"obtain":"���󽣾��ﵽ600����"]),
"̫Ԫ����":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"reduce_wood":5,"obtain":"̫Ԫ�۾��ﵽ600����"]),
"̫ʼ����":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"reduce_water":5,"obtain":"̫ʼ�۾��ﵽ600����"]),
"̫�ܵ���":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_fire":5,"obtain":"̫�ܵ۾��ﵽ600����"]),
"��սʤ��":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_earth":5,"obtain":"��սʥ���ﵽ600����"]),
"�Ϲ�ʥ��":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"jing_recover":5,"obtain":"�Ϲ��ط��ﵽ600����"]),
"��������":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"qi_recover":5,"obtain":"���������ﵽ600����"]),
"�������":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"neili_recover":5,"obtain":"��������ﵽ600����"]),
"��������":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"through_armor":5,"obtain":"�����ɾ��ﵽ600����"]),
"����ħ��":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"qi_abs_neili":5,"obtain":"����ħ���ﵽ600����"]),
"ʥ������":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"double_damage":5,"obtain":"����ʥ���ﵽ600����"]),
"��������":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"leech_neili":5,"obtain":"��֮ʥ��ﵽ600����"]),
"���淨��":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"leech_qi":5,"obtain":"��֮ʥ��ﵽ600����"]),
]);
//ת��Ϊ��������
mapping chinesename=([
"str":"�������",
"int":"��������",
"con":"�������",
"age":"����",
"dex":"������",
"max_jing":"��������",
"max_jingli":"��������",
"max_qi":"��Ѫ����",
"max_neili":"��������",
"yanjiux":"�о�Ч��",
"yanjiuc":"�о�����",
"baoji":"��������",
"baojixg":"����Ч��",
"xixue":"��Ѫ����",
"leech_qi":"����͵ȡ",
"leech_neili":"����͵ȡ",
"leech_jing":"����͵ȡ",
"double_damage":"˫���˺�",
"qi_abs_neili":"��ת����",
"through_armor":"��͸�Ƽ�",
"neili_recover":"�����ָ�",
"qi_recover":"�����ָ�",
"jing_recover":"�����ָ�",
"add_poison":"��֮�˺�",
"add_magic":"ħ֮�˺�",
"add_metal":"��֮�˺�",
"add_wood":"ľ֮�˺�",
"add_water":"ˮ֮�˺�",
"add_fire":"��֮�˺�",
"add_earth":"��֮�˺�",
"reduce_poison":"���˿���",
"reduce_magic":"ħ�˿���",
"reduce_metal":"���˿���",
"reduce_wood":"ľ�˿���",
"reduce_water":"ˮ�˿���",
"reduce_fire":"���˿���",
"reduce_earth":"���˿���",
"avoid_poison":"�����ж�",
"reputation":"����",
"sm":"�ƺ�˵��",
"bodyreset":"���޴���",
"blevel":"����ȼ�",
"per":"��ò",
"zjvip/level":"vip�ȼ�",
"yuanbao":"��ʯ",
"combat_exp":"��Ϊ",
"potential":"Ǳ��",
"qiangdaotask":"���Ź���",
"gender":"�Ա�",
"combat/MKS":"ɱ����",
"combat/dietimes":"��������",
"obtain":"��ȡ��ʽ"NOR,
]);

//��Ҫ��������ֵ
mapping need_attribute=([
"��������":(["bodyreset":5]),
"��������":(["str":100,"con":100,"int":100,"dex":100]),
"��������":(["blevel":5]),
"ɱ��":(["combat/MKS":1000000]),
"������":(["per":50,"gender":"Ů��"]),
"İ�Ͼ���":(["per":50,"gender":"����"]),
"�ݻ�����":(["zjvip/level":5]),
"���ɵй�":(["yuanbao":66666]),
"��������":(["age":100]),
"����֮��":(["combat/dietimes":100,"bodyreset":1]),
"Ϊ�����":(["qiangdaotask":1000]),
]);

//��Ҫ���ļ���
mapping need_skill=([
"���Ͻ���":(["wushang-jianjing":600]),
"��������":(["lunhui-sword":600]),
"������":(["wuyin-jianjing":600]),
"̫Ԫ����":(["wanmo-futi":600]),
"̫ʼ����":(["yinyangjiuzhuanshierchongtian":600]),
"̫�ܵ���":(["taiyan-dijing":600]),
"��սʤ��":(["douzhan-shengjing":600]),
"�Ϲ�ʥ��":(["shanggu-mijing":600]),
"��������":(["liangyi-yinyangjue":600]),
"�������":(["tianrenheyi":600]),
"��������":(["badao":600]),
"����ħ��":(["lianyu-mojing":600]),
"ʥ������":(["longwang-shengjing":600]),
"��������":(["bingzhi-shengdian":600]),
"���淨��":(["huozhi-shengdian":600]),
]);
void create() { seteuid(getuid()); }

int use_title(object me,string title)
{
mixed xg=titles[title];
string *att,at;
att=keys(xg);
me->delete("titlea");
   foreach (at in att)
   {
     if (intp(xg[at]))
     me->set("titlea/"+at,xg[at]);
  }
me->set("chenghao",title);
tell_object(me,"������˳ƺţ�"HIC+title+NOR+"\n");
	return 1;
}


string query_title(object me,string title)
{
string msg,msgg;
mixed xg=titles[title];
    if (xg)
{
msg=chinesename["obtain"]+":"+xg["obtain"]+"\n";
msg+=HIC+NOR+ZJBR"================�ƺżӳ�=================\n";

if (xg["sm"])
msg+=chinesename["sm"]+":\n"+xg["sm"]+"\n";
foreach (msgg in keys(xg))
if (intp(xg[msgg]))
msg+=HIY"("+chinesename[msgg]+")"NOR+HIW":"+xg[msgg]+NOR"\n";
if (xg=need_attribute[title])
{
msg+=HIC+NOR+ZJBR"���������������������ƺ����󡪡�������������������������"+ZJBR;
foreach (msgg in keys(xg))
if (xg[msgg])
msg+=HIY"("+chinesename[msgg]+")"NOR+HIW":"+xg[msgg]+NOR"\n";
}
       }
else
msg="�óƺ����κμӳ�\n";
	return msg;
}

mapping alltitles()
{
return titles;
}
//����ƺŴ���
int buy_title(object me,string title)
{
string att,*allatt;
mapping attribute;
//�ȼ��������Ƿ���
         if (me->query("titles/"+title))
        {
         tell_object(me,"���ѻ�øóƺš�\n");
         return 1;
         }
         
    if (need_attribute[title])
   {
   		allatt=keys(need_attribute[title]);
		attribute=need_attribute[title];
        foreach (att in allatt)
         if (me->query(att) < attribute[att])
         {
         tell_object(me,"���"+chinesename[att]+"δ��ꡣ\n");
         return 1;
         }
  
   }
//�ټ��㼼���Ƿ���
   if (need_skill[title])
   {
   allatt=keys(need_skill[title]);
attribute=need_skill[title];
       foreach (att in allatt)
         if (me->query_skill(att,1) < attribute[att])
         {
         tell_object(me,"���"+to_chinese(att)+"����"+chinese_number(attribute[att])+"����δ��ꡣ\n");
         return 1;
         }
       
   }
 //�����������Ƿ��㹻
 attribute=titles[title];
           if (me->query("reputation")<attribute["reputation"])
        {
         tell_object(me,"�������������\n");
         return 1;
         }
 me->add("potential",attribute["reputation"]/10);
 if (attribute["reputation"])
 me->add("yuanbao",1000);
 me->add("reputation",-attribute["reputation"]);
 me->set("titles/"+title,1);
 if (titles[title]["sm"])
 message("channel:chat",HBYEL+"��"+title+"��"NOR"��"+me->query("name")+"��"+replace_string(titles[title]["sm"],"\n"," ")+"\n"NOR,users());
 tell_object(me,"��ϲ���óƺ�"+HIR+title+"\n"NOR);
 return 1;
}