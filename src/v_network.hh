#ifndef VOROPP_V_NETWORK_HH
#define VOROPP_V_NETWORK_HH

#include "cell.hh"
#include "container.hh"

class voronoi_network {
	public:
		const fpoint bx,bxy,by,bxz,byz,bz;
		const int nx,ny,nz,nxyz;
		const fpoint xsp,ysp,zsp;
		fpoint **pts;
		int **idmem;
		int *ptsc;
		int *ptsmem;
		int **ed;
		int **ne;
		fpoint **raded;
		unsigned int **pered;
		int edc,edmem;
		int *nu;
		int *nec;
		int *numem;
		int *reg;
		int *regp;
		int *vmap;
		unsigned int *vper;
		int netmem;
		template<typename r_option>
		explicit voronoi_network(container_periodic_base<r_option> &c);
		~voronoi_network();
		void print_network(ostream &os=cout,bool reverse_remove=false);
		inline void print_network(const char* filename) {
			ofstream os;os.open(filename,ofstream::out|ofstream::trunc);
			print_network(os);os.close();
		}
		void draw_network(ostream &os=cout);
		inline void draw_network(const char* filename) {
			ofstream os;os.open(filename,ofstream::out|ofstream::trunc);
			draw_network(os);os.close();
		}
		template<class n_option>
		void add_to_network(voronoicell_base<n_option> &c,fpoint x,fpoint y,fpoint z,int idn);	
		template<class n_option>
		void add_to_network_rectangular(voronoicell_base<n_option> &c,fpoint x,fpoint y,fpoint z,int idn);
		void clear_network();
	private:
		inline int step_div(int a,int b);
		inline int step_int(fpoint a);
		inline void add_neighbor(int k,int idn);
		void add_particular_vertex_memory(int l);
		void add_edge_network_memory();
		void add_network_memory(int l);
		void add_mapping_memory(int pmem);
		inline unsigned int pack_periodicity(int i,int j,int k);
		inline void unpack_periodicity(unsigned int pa,int &i,int &j,int &k);
		template<class n_option>
		void add_edges_to_network(voronoicell_base<n_option> &c,fpoint x,fpoint y,fpoint z);
		bool not_already_there(int k,int j,unsigned int cper);
		bool search_previous(fpoint gx,fpoint gy,fpoint x,fpoint y,fpoint z,int &ijk,int &q,unsigned int &cper);
		bool safe_search_previous_rect(fpoint x,fpoint y,fpoint z,int &ijk,int &q,unsigned int &cper);
		bool search_previous_rect(fpoint x,fpoint y,fpoint z,int &ijk,int &q,unsigned int &cper);		
};

#endif
