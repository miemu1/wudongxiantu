inherit F_CLEAN_UP;
mapping mlist =
([
"ؤ��"     : "d/city/gbxiaowu",
"����" : "d/mingjiao/dadian",
"ȫ���"   : "d/quanzhen/shiweishi",
"������"   : "d/emei/hcahoudian",
"��Ĺ��"   : "d/gumu/zhengting",
"��ɽ��"   : "d/huashan/qunxianguan",
"���չ�"   : "d/lingjiu/dating",
"������"   : "d/shaolin/fzlou2",
"������"   : "d/shenlong/dating",
"�һ���"   : "d/taohua/dating",
"�䵱��"   : "d/wudang/xiaoyuan.c",
"��ң��"   : "d/xiaoyao/qingcaop",
"������"   : "d/xingxiu/riyuedong",
"Ѫ����"   : "d/xuedao/shandong3",
"ѩɽ��"   : "d/xueshan/neidian",
"���ϻ���" : "d/dali/neitang",
"Ľ������" : "d/yanziwu/shangyu",
"ŷ������" : "d/baituo/dating",
"�������" : "d/guanwai/xiaowu",
"��ɽ����" : "d/huashan/xiaowu",
"�������" : "d/heimuya/up1",
"����" : "d/tangmen/qianliju",
]);

int main(object me) {

/**
    if (me->is_busy()) {
        return notify_fail("����æ���ء�\n");
    }
    if (me->is_ghost()) {
        return notify_fail("���㻹������˵�ɡ�\n");
    }

    if (me->is_in_prison()) {
        return notify_fail("�����������ء�\n");
    }
    if (!me->query("born")) {
        return notify_fail("�㻹û�г����أ�\n");
    }
    if (me->query("doing")) {
        return notify_fail("�㻹���ʲô����\n");
    }


        if (me->is_ghost()){
            return notify_fail("���㻹������˵�ɡ�\n");
        }

            if (me->query("doing")){
            return notify_fail("�㻹���ʲô����\n");
        } */

    string my_fam = me->query("family/family_name");

    me->move(mlist[my_fam]);
    return 1;

};
  