namespace CommonTools {

template<typename MapType>
struct map_init_helper
{
    MapType& map;
    map_init_helper(MapType& m) : map(m) {}
    map_init_helper& operator()(typename MapType::key_type const& key, typename MapType::mapped_type const& value)
    {
        map[key] = value;
        return *this;
    }

    typename MapType::mapped_type const& operator[](typename MapType::key_type const& key)
    {
        return map[key];
    }
};

template<typename MapType>
constexpr map_init_helper<MapType> map_init(MapType& item)
{
    return map_init_helper<MapType>(item);
}

}
