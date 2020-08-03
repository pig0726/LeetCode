
class UndergroundSystem {
public:
    using pss = pair<string, string>;
    using pii = pair<int, int>;
    using psi = pair<string, int>;
    map<pss, pii> tdata;
    map<int, psi> cdata;

    UndergroundSystem() {
    }

    void checkIn(int id, string sN, int t) {
      psi data = make_pair(sN, t);
      cdata[id] = data;
    }

    void checkOut(int id, string sN, int t) {
      const psi& data = cdata[id];
      pss ss = make_pair(data.first, sN);
      int delta = t - data.second;

      auto it = tdata.find(ss);

      if (it == tdata.end()) {
        pii tmp = make_pair(1, delta);
        tdata.insert(make_pair(ss, tmp));
      } else {
        it->second.first += 1;
        it->second.second += delta;
      }
    }

    double getAverageTime(string sS, string eS) {
      double ret = 0;
      pss se = make_pair(sS, eS);
      auto it = tdata.find(se);
      if (it != tdata.end())
        ret = 1. * it->second.second / it->second.first;
      return ret;
    }
};



/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
