#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<double>::infinity()
#define EARTH_RADIUS 6371.0 // Radius of Earth in kilometers
// Structure to store latitude and longitude
struct Location
{
  string name;
  double latitude;
  double longitude;
};
// Function to calculate distance between two locations using Haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2)
{
  double dLat = (lat2 - lat1) * M_PI / 180.0;
  double dLon = (lon2 - lon1) * M_PI / 180.0;
  // convert to radians
  lat1 = (lat1) * M_PI / 180.0;
  lat2 = (lat2) * M_PI / 180.0;
  // apply formulae
  double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
  double rad = 6371;
  double c = 2 * asin(sqrt(a));
  return rad * c;
}

// Graph class for Dijkstra’s Algorithm
class Graph
{
public:
  unordered_map<string, vector<pair<string, double>>> adjList;
  unordered_map<string, Location> locations;

  void addLocation(string name, double lat, double lon)
  {
    locations[name] = {name, lat, lon};
  }
  void addEdge(string loc1, string loc2)
  {
    if (locations.find(loc1) == locations.end() || locations.find(loc2) == locations.end())
    {
      cout << "Invalid locations: " << loc1 << " or " << loc2 << "\n";
      return;
    }
    double distance = haversine(locations[loc1].latitude, locations[loc1].longitude,locations[loc2].latitude, locations[loc2].longitude);
    adjList[loc1].push_back({loc2, distance});
    adjList[loc2].push_back({loc1, distance});
  }

  void dijkstra(string src, string dest)
  {
    if (locations.find(src) == locations.end() || locations.find(dest) == locations.end())
    {
      cout << "Invalid source or destination location!\n";
      return;
    }

    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<>> pq;
    unordered_map<string, double> dist;
    unordered_map<string, string> parent;

    for (auto &loc : locations)
      dist[loc.first] = INF;
    dist[src] = 0.0;
    pq.push({0.0, src});

    while (!pq.empty())
    {
      auto [currDist, curr] = pq.top();
      pq.pop();

      if (curr == dest)
        break;

      for (auto &[neighbor, weight] : adjList[curr])
      {
        if (dist[curr] + weight < dist[neighbor])
        {
          dist[neighbor] = dist[curr] + weight;
          pq.push({dist[neighbor], neighbor});
          parent[neighbor] = curr;
        }
      }
    }

    if (dist[dest] == INF)
    {
      cout << "No path found from " << src << " to " << dest << "\n";
      return;
    }
    // Printing shortest path
    vector<string> path;
    for (string at = dest; at != ""; at = parent[at])
    {
      path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << "Shortest path from " << src << " to " << dest << ":\n";
    for (size_t i = 0; i < path.size(); ++i)
    {
      cout << path[i];
      if (i < path.size() - 1)
        cout << " -> ";
    }
    cout << "\nTotal Distance: " << dist[dest] << " km\n";
  }
};
int main()
{
  Graph g;
  // Adding locations on IIT ISM campus
  g.addLocation("Teacher Colony", 23.811006, 86.444536);
  g.addLocation("Teacher Colony Park", 23.810899, 86.444312);
  g.addLocation("Main Gate", 23.809267, 86.442595);
  g.addLocation("IIT ISM Complex", 23.808995192028906, 86.44315696834926);
  g.addLocation("Rock Garden", 23.809848964416208, 86.44269375288253);
  g.addLocation("ISM Campus Administration office", 23.810049258267142, 86.44273790142529);
  g.addLocation("UGC Park", 23.81042936910972, 86.4421999495077);
  g.addLocation("India Post Office", 23.811298335627754, 86.44220600578193);
  g.addLocation("SBI ATM", 23.811737755983543, 86.44213799135692);
  g.addLocation("ism Upper Ground", 23.812968247708444, 86.44103740741127);
  g.addLocation("Oval Ground", 23.813947659514543, 86.44117937832681);
  g.addLocation("Academic Complex", 23.811458663584844, 86.44097944403728);
  g.addLocation("Academic Building Dep.Electrical", 23.81165166908888, 86.44153585273284);
  g.addLocation("BTECH Common Physics Laboratory", 23.811451173981755, 86.44153587379351);
  g.addLocation("Dept.of Physics", 23.811414628186316, 86.44094501129592);
  g.addLocation("Nescafe Academic Complex IIT (ISM)", 23.81156565765959, 86.44164954421544);
  g.addLocation("civil Eng.Dept.", 23.811666084625685, 86.44053179747169);
  g.addLocation("Temple", 23.81126732646057, 86.44000876671427);
  g.addLocation("ECE Dept.", 23.811749516944538, 86.4406605435044);
  g.addLocation("Faculty Apartments", 23.81051936757431, 86.43984942571147);
  g.addLocation("ISM Children park", 23.810482697338056, 86.4377954000262);
  g.addLocation("IIT Health center", 23.811909326501862, 86.43907584249969);
  g.addLocation("Prathmik Vidhyalay Ismag", 23.810987563624764, 86.43767113828261);
  g.addLocation("ism durga Mandap", 23.812038343398534, 86.43800569319207);
  g.addLocation("Management Dept.", 23.812185695349857, 86.44044679231551);
  g.addLocation("Computer Science & eng. dept.", 23.81187896670652, 86.44089027697214);
  g.addLocation("EDC,IIT Dhanbad", 23.81208107255118, 86.44139042181848);
  g.addLocation("ISM ENVIS Centre", 23.812434355588014, 86.43987803033198);
  g.addLocation("Environmental Dept.", 23.812612967607, 86.44007466670409);
  g.addLocation("Fuel & Mineral Eng. Dept.", 23.812814092356874, 86.43960096957758);
  g.addLocation("Mechanical Eng. Dept.", 23.81318880607225, 86.43944718007843);
  g.addLocation("staff Recreation club", 23.812764227768003, 86.43773911235505);
  g.addLocation("ISM Sports Office", 23.8128925159869, 86.43810655482017);
  g.addLocation("Longwall Laboratory", 23.81297765521346, 86.43830774536784);
  g.addLocation("Scolomin House", 23.811124316287476, 86.44315079764343);
  g.addLocation("Eco Vatika", 23.8130110587712, 86.44432373355268);
  g.addLocation("Ruby Hostel", 23.813319, 86.444558);
  g.addLocation("Rosaline hostel", 23.813339, 86.445116);
  g.addLocation("Ruby garden", 23.813194, 86.443464);
  g.addLocation("international hostel", 23.813684, 86.444564);
  g.addLocation("ISM staff Quaters", 23.813843, 86.447296);
  g.addLocation("IIT ISM shooting range", 23.814539167578392, 86.44361707890926);
  g.addLocation("Seismological observatory", 23.815225369415046, 86.44405829443161);
  g.addLocation("Central library", 23.816031385738487, 86.44223898687098);
  g.addLocation("Petroleum eng. Dept.", 23.815553021387483, 86.44298516390522);
  g.addLocation("Dept. of Humanities and social science", 23.81564453226454, 86.44301049568892);
  g.addLocation("Jasper garden", 23.816611376572983, 86.44163519917413);
  g.addLocation("Old library", 23.81513226374244, 86.44200413270488);
  g.addLocation("Dept. of Geophysics", 23.814917312916386, 86.44281529195113);
  g.addLocation("Applied Geophysics Annexure Building", 23.814874144540475, 86.44314183080567);
  g.addLocation("Main Canteen", 23.815107312745887, 86.44157835722696);
  g.addLocation("Penman Auditorium", 23.814950097979672, 86.44121938819042);
  g.addLocation("opal Hostel", 23.815625537855638, 86.44142560444527);
  g.addLocation("Jasper Hostel", 23.816542250138436, 86.44079035997223);
  g.addLocation("Ram Dhani Tea Shop", 23.81641067245755, 86.4402725887723);
  g.addLocation("Pumping Station", 23.81736329185864, 86.4393175885577);
  g.addLocation("Gymkhana Ground", 23.81774223243969, 86.43880844687762);
  g.addLocation("Amber Hostel", 23.81855800356462, 86.439665645864);
  g.addLocation("Topaz Hostel", 23.818679053038714, 86.43794837138189);
  g.addLocation("SAC", 23.81738913547373, 86.43760543659683);
  g.addLocation("Weightlifting Centre", 23.81700123186388, 86.43764535655461);
  g.addLocation("Basketball Court", 23.81701161767603, 86.43887491165061);
  g.addLocation("New Sports Complex", 23.816820650283514, 86.43885403725781);
  g.addLocation("Boxing Ground", 23.817582748564945, 86.4373417045422);
  g.addLocation("NLHC", 23.816376650009975, 86.43943330165732);
  g.addLocation("ISM Swimming Pool", 23.817673373727096, 86.43767622639821);
  g.addLocation("NCC IIT", 23.81883694348143, 86.43716020855481);
  g.addLocation("ISM Dhaiya Gate", 23.82020005633361, 86.43497981649932);
  g.addLocation("Karma Jyoti", 23.81748594205593, 86.43746380271563);
  g.addLocation("International EDC", 23.81567409708862, 86.43973572929151);
  g.addLocation("Central Workshop", 23.814835079121096, 86.43937178565523);
  g.addLocation("GJLT", 23.814019428163736, 86.44027973343239);
  g.addLocation("HSE Dept.", 23.813707542584293, 86.44042060460194);
  g.addLocation("OLHC", 23.814096828165862, 86.44016845294931);
  g.addLocation("Open Air Theatre", 23.81406434003306, 86.44006105140387);
  g.addLocation("Science Block", 23.814633163354287, 86.44010940059039);
  g.addLocation("Chemistry Laboratory for UG", 23.81315035357867, 86.44025674622185);
  g.addLocation("Petrified Wood", 23.813767704625345, 86.44121128965962);
  g.addLocation("Dept. of Applied Geology", 23.81444576642195, 86.44140314243705);
  g.addLocation("Main building", 23.81448907141411, 86.44122060387576);
  g.addLocation("Mining Eng. Dept.", 23.814435932593568, 86.44095020312614);
  g.addLocation("Applied Geophysics Dept.", 23.814647, 86.441618);
  g.addLocation("ism Lower Ground", 23.813032247560763, 86.44261838542626);
  g.addLocation("Administrative Block", 23.81416193343172, 86.44236833542587);
  g.addLocation("Examination Section", 23.814504066113194, 86.44252118122778);
  g.addLocation("Director's Office", 23.814315670461074, 86.44260787271526);
  g.addLocation("Diamond Hostel", 23.815416402851447, 86.44051836804135);

  g.addEdge("Main Gate", "Rock Garden");
  g.addEdge("Main Gate", "Teacher Colony");
  g.addEdge("Main Gate", "IIT ISM Complex");
  g.addEdge("IIT ISM Complex", "Teacher Colony");
  g.addEdge("Teacher Colony Park", "Teacher Colony");
  g.addEdge("ISM Campus Administration office", "Rock Garden");
  g.addEdge("ISM Campus Administration office", "UGC Park");
  g.addEdge("UGC Park", "Faculty Apartments");
  g.addEdge("Faculty Apartments", "ISM Children park");
  g.addEdge("UGC Park", "India Post Office");
  g.addEdge("India Post Office", "Academic Complex");
  g.addEdge("Faculty Apartments", "Academic Complex");
  g.addEdge("Academic Complex", "Dept.of Physics");
  g.addEdge("Academic Complex", "Temple");
  g.addEdge("Academic Complex", "civil Eng.Dept.");
  g.addEdge("Academic Complex", "ECE Dept.");
  g.addEdge("Academic Complex", "BTECH Common Physics Laboratory");
  g.addEdge("Temple", "IIT Health center");
  g.addEdge("Temple", "Management Dept.");
  g.addEdge("Temple", "Computer Science & eng. dept.");
  g.addEdge("IIT Health center", "Prathmik Vidhyalay Ismag");
  g.addEdge("IIT Health center", "ism durga Mandap");
  g.addEdge("IIT Health center", "staff Recreation club");
  g.addEdge("ism durga Mandap", "staff Recreation club");
  g.addEdge("ism durga Mandap", "Prathmik Vidhyalay Ismag");
  g.addEdge("staff Recreation club", "ISM Sports Office");
  g.addEdge("ISM Sports Office", "Longwall Laboratory");
  g.addEdge("Computer Science & eng. dept.", "EDC,IIT Dhanbad");
  g.addEdge("EDC,IIT Dhanbad", "ISM ENVIS Centre");
  g.addEdge("EDC,IIT Dhanbad", "Environmental Dept.");
  g.addEdge("EDC,IIT Dhanbad", "Mechanical Eng. Dept.");
  g.addEdge("Mechanical Eng. Dept.", "Fuel & Mineral Eng. Dept.");
  g.addEdge("EDC,IIT Dhanbad", "SBI ATM");
  g.addEdge("SBI ATM", "India Post Office");
  g.addEdge("India Post Office", "Academic Building Dep.Electrical");
  g.addEdge("Academic Building Dep.Electrical", "Nescafe Academic Complex IIT (ISM)");
  g.addEdge("SBI ATM", "ism Upper Ground");
  g.addEdge("India Post Office", "Scolomin House");
  g.addEdge("Scolomin House", "Ruby garden");
  g.addEdge("Ruby garden", "Ruby Hostel");
  g.addEdge("Ruby Hostel", "Eco Vatika");
  g.addEdge("Ruby Hostel", "Rosaline hostel");
  g.addEdge("Ruby garden", "ism Lower Ground");
  g.addEdge("ism Lower Ground", "Administrative Block");
  g.addEdge("Administrative Block", "Examination Section");
  g.addEdge("Administrative Block", "Director's Office");
  g.addEdge("Administrative Block", "Applied Geophysics Annexure Building");
  g.addEdge("Applied Geophysics Annexure Building", "Seismological observatory");
  g.addEdge("Applied Geophysics Annexure Building", "IIT ISM shooting range");
  g.addEdge("IIT ISM shooting range", "international hostel");
  g.addEdge("IIT ISM shooting range", "ISM staff Quaters");
  g.addEdge("Applied Geophysics Annexure Building", "Petroleum eng. Dept.");
  g.addEdge("Petroleum eng. Dept.", "Central library");
  g.addEdge("Petroleum eng. Dept.", "Dept. of Humanities and social science");
  g.addEdge("Central library", "Jasper garden");
  g.addEdge("Central library", "Old library");
  g.addEdge("Ram Dhani Tea Shop", "Jasper garden");
  g.addEdge("Ram Dhani Tea Shop", "Jasper Hostel");
  g.addEdge("Ram Dhani Tea Shop", "Pumping Station");
  g.addEdge("Ram Dhani Tea Shop", "NLHC");
  g.addEdge("Pumping Station", "Gymkhana Ground");
  g.addEdge("Pumping Station", "New Sports Complex");
  g.addEdge("Pumping Station", "NLHC");
  g.addEdge("Gymkhana Ground", "Amber Hostel");
  g.addEdge("Gymkhana Ground", "Topaz Hostel");
  g.addEdge("Gymkhana Ground", "Weightlifting Centre");
  g.addEdge("Gymkhana Ground", "SAC");
  g.addEdge("New Sports Complex", "Basketball Court");
  g.addEdge("Karma Jyoti", "SAC");
  g.addEdge("ISM Swimming Pool", "SAC");
  g.addEdge("Boxing Ground", "SAC");
  g.addEdge("NCC IIT", "Topaz Hostel");
  g.addEdge("NCC IIT", "ISM Dhaiya Gate");
  g.addEdge("NLHC", "International EDC");
  g.addEdge("International EDC", "Central Workshop");
  g.addEdge("International EDC", "Science Block");
  g.addEdge("International EDC", "Diamond Hostel");
  g.addEdge("International EDC", "OLHC");
  g.addEdge("OLHC", "Open Air Theatre");
  g.addEdge("OLHC", "GJLT");
  g.addEdge("GJLT", "HSE Dept.");
  g.addEdge("GJLT", "Oval Ground");
  g.addEdge("GJLT", "Science Block");
  g.addEdge("Oval Ground", "Petrified Wood");
  g.addEdge("Oval Ground", "Main building");
  g.addEdge("Oval Ground", "Science Block");
  g.addEdge("Oval Ground", "Administrative Block");
  g.addEdge("Oval Ground", "ism Upper Ground");
  g.addEdge("ism Upper Ground", "Chemistry Laboratory for UG");
  g.addEdge("Main building", "Mining Eng. Dept.");
  g.addEdge("Main building", "Applied Geophysics Dept.");
  g.addEdge("Main building", "Dept. of Applied Geology");
  g.addEdge("Diamond Hostel", "opal Hostel");
  g.addEdge("opal Hostel", "Main Canteen");
  g.addEdge("opal Hostel", "Old library");
  g.addEdge("Main Canteen", "Old library");
  g.addEdge("Main Canteen", "Penman Auditorium");
  g.addEdge("Old library", "Dept. of Geophysics");
  g.addEdge("Dept. of Geophysics", "Applied Geophysics Annexure Building");
  g.addEdge("Central Workshop", "Longwall Laboratory");
  g.addEdge("Old library", "Administrative Block");
  g.addEdge("Applied Geophysics Annexure Building", "Ruby garden");
  g.addEdge("Chemistry Laboratory for UG", "ism Upper Ground");
  // Finding shortest path
  string src, dest;
  cout << "Enter source location: ";
  getline(cin, src);
  cout << "Enter destination location: ";
  getline(cin, dest);
  g.dijkstra(src, dest);
  return 0;
}