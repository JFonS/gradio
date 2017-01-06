/* This file is part of Gradio.
 *
 * Gradio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Gradio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Gradio.  If not, see <http://www.gnu.org/licenses/>.
 */

namespace Gradio{

	public class CategoryItemProvider{

		public GLib.List<string> languages_list;
		public GLib.List<string> countries_list;
		public GLib.List<string> codecs_list;
		public GLib.List<string> states_list;
		public GLib.List<string> tags_list;

		public signal void loaded();

		public CategoryItemProvider(){
			load_lists.begin();
		}

		private async void load_lists (){
        		SourceFunc callback = load_lists.callback;

			message("Fetching category items...");

			ThreadFunc<void*> run = () => {
				languages_list = null;
				languages_list = new GLib.List<string>();

				try{
					Json.Parser parser = new Json.Parser ();
					string data = "";

					// Languages
					Util.get_string_from_uri.begin(RadioBrowser.radio_station_languages, (obj, res) => {
						data = Util.get_string_from_uri.end(res);

						if(data != ""){
							parser.load_from_data (data);
							var root = parser.get_root ();
							var languages = root.get_array ();
							int max_items = (int)languages.get_length();
							for(int a = 0; a < max_items; a++){
								var language = languages.get_element(a);
								var language_data = language.get_object ();
								languages_list.append(language_data.get_string_member("value"));
							}
						}
					});


					// Codecs
					Util.get_string_from_uri.begin(RadioBrowser.radio_station_codecs, (obj, res) => {
						data = Util.get_string_from_uri.end(res);

						if(data != ""){
							parser.load_from_data (data);
							var root = parser.get_root ();
							var codecs = root.get_array ();
							int max_items = (int)codecs.get_length();
							for(int a = 0; a < max_items; a++){
								var codec = codecs.get_element(a);
								var codec_data = codec.get_object ();
								codecs_list.append(codec_data.get_string_member("value"));
							}
						}
					});



					// Countries
					Util.get_string_from_uri.begin(RadioBrowser.radio_station_countries, (obj, res) => {
						data = Util.get_string_from_uri.end(res);

						if(data != ""){
							parser.load_from_data (data);
							var root = parser.get_root ();
							var countries = root.get_array ();
							int max_items = (int)countries.get_length();
							for(int a = 0; a < max_items; a++){
								var country = countries.get_element(a);
								var country_data = country.get_object ();
								countries_list.append(country_data.get_string_member("value"));
							}
						}
					});


					// States
					Util.get_string_from_uri.begin(RadioBrowser.radio_station_states, (obj, res) => {
						data = Util.get_string_from_uri.end(res);

						if(data != ""){
							parser.load_from_data (data);
							var root = parser.get_root ();
							var states = root.get_array ();
							int max_items = (int)states.get_length();
							for(int a = 0; a < max_items; a++){
								var state = states.get_element(a);
								var state_data = state.get_object ();
								states_list.append(state_data.get_string_member("value"));
							}
						}
					});


					// Tags
					Util.get_string_from_uri.begin(RadioBrowser.radio_station_tags, (obj, res) => {
						data = Util.get_string_from_uri.end(res);

						if(data != ""){
							parser.load_from_data (data);
							var root = parser.get_root ();
							var tags = root.get_array ();
							int max_items = (int)tags.get_length();
							for(int a = 0; a < max_items; a++){
								var tag = tags.get_element(a);
								var tag_data = tag.get_object ();
								tags_list.append(tag_data.get_string_member("value"));
							}
						}
					});



				}catch(GLib.Error e){
					warning(e.message);
				}
				Idle.add((owned) callback);
				Thread.exit (1.to_pointer ());
				return null;
			};

			new Thread<void*> ("load_list_thread", run);

			yield;
			message("Successfully loaded category items!");
			loaded();
        	}

	}
}
